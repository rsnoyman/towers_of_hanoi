#! /usr/bin/env python3

import sys 
from hanoi_tools import * 

n = -1

# Attempt to read from command line
if len(sys.argv) == 2:
	try:
		n = int(sys.argv[1])
	except:
		pass

# Else ask for input until valid n given
while not (isinstance(n, int) and n > 0):
	try:
		n = int(input("Please enter a positive integer: "))
	except:
		continue

board = Board(n)

solve_hanoi(board)



