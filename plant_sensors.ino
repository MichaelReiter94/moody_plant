int plantInput = 0;
int plant_sensor;


void setup() {
  pinMode(plantInput, INPUT);

  Serial.begin(9600);
}

void loop() {




  plant_sensor = analogRead(plantInput);
  
  Serial.print("A");
  Serial.println(plant_sensor);
  
  delay(10);
}
