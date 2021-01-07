#!/usr/bin/env python3

import os

import serial
import playsound

"""
Args:
	comPortNumber(string)
	baudRate(int)
	timeout(double)

example use:
	>>> soundPlayer = SoundPlayer('COM5', 115200, 0.1)
	>>> soundPlayer.play()
"""
class SoundPlayer():
	def __init__(self, com_port_number='COM5', 
					   baud_rate=115200, 
					   timeout=0.1,
					   sound_files_path='/sound_files/'):
		self.arduino = serial.Serial(com_port_number, baud_rate, timeout)
		self.buttonPressed = 0
		self.sound_files_path = sound_files_path

	def read_arduino(self):
		while True:
			data_from_arduino = self.arduino.readline()[:-2]
			if data_from_arduino:
				print(data_from_arduino)
				self.button_pressed = int(data_from_arduino[-1])

	def play(self):
		self.read_arduino()

		for root, dirs, files in os.walk(self.sound_files_path):
			if str(self.button_pressed) in files:
				sound_file_path = os.path.join(root, str(self.button_pressed))
		playsound(sound_file_path)