# Python script for displaying/playing Arduino script.
import serial
arduino = serial.Serial('COM5', 115200, timeout=.1)
while True:
	data = arduino.readline()[:-2] 
	if data:
		print(data)