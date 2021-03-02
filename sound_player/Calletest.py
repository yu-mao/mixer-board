import os
import re
import serial
import sys
from playsound import playsound
class SoundPlayer():

#Initializing setup

	def __init__(self, com_port_number='COM5', 
					   baud_rate=115200, 
					   timeout=0.1,
					   sound_files_path='./sound_files/'):
		self.arduino = serial.Serial(com_port_number, baud_rate, timeout=timeout)
		self.button_pressed  = 0
		self.sound_files_path = sound_files_path

#Reading arduino output

	def reader(self):
			while True:
				output_arduino = self.arduino.readline()[:-2]
				if output_arduino:
					button_pressed = output_arduino[-1]
					if button_pressed != self.button_pressed:
						self.button_pressed = button_pressed
						print(button_pressed)
						self.player()
					

#Reads which button is pressed and plays the corresponding sound file

	def player(self):
			if self.button_pressed == 49:
				playsound('./sound_files/1.wav')

			elif self.button_pressed == 50:
				playsound('./sound_files/2.wav')

			elif self.button_pressed == 51:
				playsound('./sound_files/3.wav')

			elif self.button_pressed == 52:
				playsound('./sound_files/4.wav')

#This part makes the program run in cmd
if __name__ == "__main__":
	soundPlayer = SoundPlayer()
	soundPlayer.reader()

