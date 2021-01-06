#include <TrueRMS.h>

#include <DCfilter.h>
// #include <Arduino.h>
#include <MozziGuts.h>
#include <StateVariable.h>
#include <LowPassFilter.h>
#include <RollingStat.h>

#pragma region declarations
#define RMS_WINDOW 60
const int inputPin = A0;
const int outputPin = 3;
const int debugTriggerPin = A3;
const int controlFilterFrequencyPin = A2;

float frequency = 250.0f;
float fs = 800.0;                     //Hertz
unsigned long samplingIntervallMs;   //miliseconds

LowPassFilter lopFilter;
// StateVariable<filter_types::HIGHPASS> stateVariableFilter;
DCfilter dcFilter(0.2);
Rms rms;
// RollingStat<int,1000> movingAverage;
// RollingAverage<int, 10> movingAverage;

int inputValue;
int outputSignal;
int debugTriggerInput;
int controlFilterFrequencyInput;

unsigned long debugMilis = 0;
unsigned long previousMillis = 0;
unsigned int iter = 0;
int cylce = 0;
int drawPlotForSeconds = 2;
int debug_iter = 0;

#pragma endregion

void setup()
{

   pinMode(inputPin, INPUT);
   pinMode(outputPin, OUTPUT);
   // pinMode(debugTriggerPin, INPUT);
   // pinMode(controlFilterFrequencyPin, INPUT);

   rms.begin(1024.0f, RMS_WINDOW, ADC_10BIT, BLR_OFF, CNT_SCAN);
   rms.start();
   lopFilter.setCutoffFreqAndResonance(100, 50);

   Serial.begin(9600);
   samplingIntervallMs = static_cast<unsigned long> (1000.0f / fs);
   // stateVariableFilter.setCentreFreq(400);
   // stateVariableFilter.setResonance(100);
}


void loop()
{
   // method called every sampling instance (every 1/fs seconds)
   if (millis() - previousMillis >= samplingIntervallMs)
   { 

      float outputSignalTrigger =  sin ( 2 * PI * frequency * iter / fs);
      iter++;

      if (outputSignalTrigger > 0) {
         outputSignal = HIGH;
      } else{
         outputSignal = LOW;
      }
      digitalWrite(outputPin, outputSignal);

      // // // // // // controlFilterFrequencyInput = analogRead(controlFilterFrequencyPin);  
      // // // // // // stateVariableFilter.setCentreFreq(controlFilterFrequencyInput * 4);


      inputValue = analogRead(inputPin)-512;
      inputValue = dcFilter.next(inputValue);
      // inputValue = stateVariableFilter.next(inputValue);


      rms.update(inputValue);
      rms.publish();

      // Serial.print(450);
      // Serial.print(",");
      // Serial.print(350);
      // Serial.print(",");
      // Serial.print(250);
      // Serial.print(",");
      if (iter % (int)(fs/25) == 1)
      {
         Serial.print("A");
         Serial.println((int)(rms.rmsVal));
      }

      // inputValue = sqrt(inputValue*inputValue);

      // inputValue = lopFilter.next(inputValue);

      // inputValue = stateVariableFilter.next(inputValue);

      // int mean = movingAverage.next(inputValue);

      // movingAverage.update(inputValue);
      // int mean = movingAverage.getVariance();

      // debugTriggerInput = analogRead(debugTriggerPin);
      // if (debugTriggerInput > 900)
      // {
      //    debug_iter = 0;
      // }

      // if (debug_iter < fs * drawPlotForSeconds)
      // {

      // if (iter % 10 > 3)
      // {
      // Serial.println(outputSignal * 1023);
      // Serial.println(mean);
      // Serial.print(","); 
      // Serial.println(512);
      // Serial.print(",");
      // Serial.println(-512);
      // Serial.print(",");
      // Serial.println(inputValue);
      // }

      // debug_iter++;
      // Serial.print(" seconds: ");
      // Serial.println(cylce);
      // cylce++;
      // cylce = cylce % 10;

      // iter = 0;

      // debugMilis = millis()-debugMilis;
      // Serial.println(debugMilis);
      // debugMilis = millis();
      // }

      previousMillis = millis();


   }

}
