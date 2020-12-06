#!/usr/bin/env python
import sys
from math import ceil


def calculate(ducks, bread_nutritiousness, bread_price):
	loafs = ceil(ducks / bread_nutritiousness)
	money_required = loafs * bread_price
	return money_required

def main(argv):
	while True:
		try:
			ducks = int(input("How many ducks? "))
			bread_nutritiousness = float(input("A single loaf feeds this many ducks: "))
			bread_price = float(input("Bread price per loaf: "))
		except ValueError:
			print("Come again?")
			continue
		else:
			if ducks <= 0:
				print("Ducks too ephemeral to feed on bread!")
				return 1
			elif bread_nutritiousness <=0:
				print("Bread is devouring ducks!")
				return 2
			elif bread_price <= 0:
				print("Have you invested into bread futures?")
				return 3
			else:
				money_required = calculate(ducks,
				                           bread_nutritiousness,
				                           bread_price)
				print("--------------")
				print("Money to spend: ", money_required)
	return 0

if __name__ == '__main__':
	sys.exit(main(sys.argv))