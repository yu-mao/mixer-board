#!/usr/bin/env python3

import os

import serial
from playsound import playsound

"""
Args:
	comPortNumber(string)
	baudRate(int)
	timeout(double)

example use:
	>>> soundPlayer = SoundPlayer('COM5', 115200, 0.1)
	>>> soundPlayer.read_arduino()
"""
class SoundPlayer():
	def __init__(self, com_port_number='COM5', 
					   baud_rate=115200, 
					   timeout=0.1,
					   sound_files_path='./sound_files/'):
		self.arduino = serial.Serial(com_port_number, baud_rate, timeout=timeout)
		self.button_pressed  = 0
		self.sound_files_path = sound_files_path

# TODO: detect button press CHANGE
	def read_arduino(self):
		while True:
			data_from_arduino = self.arduino.readline()[:-2]
			if data_from_arduino:
				button_pressed = (data_from_arduino[-1] + 2) % 10
				if button_pressed != self.button_pressed:
					self.button_pressed = button_pressed
					print(self.button_pressed)
					self.play()

	def play(self):
		sound_file_names = os.listdir(self.sound_files_path)
		for sound_file_name in sound_file_names:
			if str(self.button_pressed) in sound_file_name:
				sound_files_path = self.sound_files_path + sound_file_name
				playsound(sound_files_path)


if __name__ == "__main__":
	soundPlayer = SoundPlayer()
	soundPlayer.read_arduino()