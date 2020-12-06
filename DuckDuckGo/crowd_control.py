#!/usr/bin/env python
import sys
import csv


def load_array():
	with open('pond.csv') as pond_file:
		data = list(csv.reader(pond_file, delimiter='\t'))
	return data

def main(argv):
	try:
		ducks_needed = int(input("How many ducks will break a loaf apart? "))
	except ValueError:
		print("Come again?")
		return 1
	if ducks_needed <= 0:
		print("Bread is too powerful.")
		return 2
	pond = load_array()

	max_y = len(pond)
	unleash_ducks = 0

	for row in range(max_y):
		max_x = len(pond[row])
		for tile in range(max_x):
			sides = 4
			try:
				is_loaf = int(pond[row][tile])
			except ValueError:
				print("Interference on pond radar... Abort duck deployment!")
				return 3
			if is_loaf:
				if row == 0 or row == max_y - 1:
					sides -= 1
				if tile == 0 or tile == max_x - 1:
					sides -= 1
				unleash_ducks += sides * ducks_needed
	print("Unleash " + str(unleash_ducks) + " ducks!")
	return 0

if __name__ == '__main__':
	sys.exit(main(sys.argv))