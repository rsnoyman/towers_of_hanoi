#! /usr/bin/env python3

import sys
from hanoi import solve_hanoi

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

solve_hanoi(n)
