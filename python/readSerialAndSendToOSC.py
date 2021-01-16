import time
import serial
from pythonosc import udp_client

ser = serial.Serial('/dev/ttyACM0', 9600, timeout=5)
client = udp_client.SimpleUDPClient("127.0.0.1", 8000)
while 1:
    input_string = ser.readline().decode("utf-8").strip()
    print(input_string)
    client.send_message("/A", int(input_string[1:]))
    # print("time")
    # ser.readline always waits until it receives the NEXT serial input??
    # so ther probably should NOT be a sleep() method call
    time.sleep(0.001)