import os

import pygame
import serial

class SoundPlayer():
	def __init__(self, com_port_number='COM5', 
					   baud_rate=115200, 
					   timeout=0.1,
					   sound_files_path='./sound_files/'):
		self.arduino = serial.Serial(com_port_number, baud_rate, timeout=timeout)
		self.button_pressed  = 0
		self.sound_files_path = sound_files_path

#Transform output from arduino board to input into readable 
#Python expressions

		def reader(self):
			while True:
				button_pressed = output_arduino

#Reads which button is pressed and makes the computer
#play corresponding file
		def player(self):
			if button_pressed == 1
			playsound('C:\Users\calle\OneDrive\Skrivbord\Mixer-board\sound_player\sound_files\1.wav')

			else if button_pressed == 2
			playsound('C:\Users\calle\OneDrive\Skrivbord\Mixer-board\sound_player\sound_files\2.wav')

			else if button_pressed == 3
			playsound('C:\Users\calle\OneDrive\Skrivbord\Mixer-board\sound_player\sound_files\3.wav')

			else if button_pressed == 4
			playsound('C:\Users\calle\OneDrive\Skrivbord\Mixer-board\sound_player\sound_files\4.wav')




