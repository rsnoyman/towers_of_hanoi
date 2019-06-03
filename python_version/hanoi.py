BOARD_SIZE = 3

def block_str(n, size):
	block = ''

	block += ' '*(n-size)
	block += '='*(size)
	block += '|'
	block += '='*(size)
	block += ' '*(n-size)

	return block


class Board():
	def __init__(self, n):
		self.board = [list(range(n,0,-1)), [], []]
		self.n = n

	def __len__(self):
		return self.n

	def __str__(self):
		output = ''

		curr = []
		for pole in range(BOARD_SIZE):
			curr.append(len(self.board[pole]) - 1)

		for lvl in range(self.n,0,-1):
			for pole in range(BOARD_SIZE):
				# If stack is less than height lvl, print empty block
				if len(self.board[pole]) < lvl:
					output += block_str(self.n, 0)
				else:
					output += block_str(self.n, self.board[pole][curr[pole]])
					curr[pole] = curr[pole] - 1
			output += '\n'

		return output
	
	def move_disc(self, f, t):
		disc = self.board[f].pop()
		self.board[t].append(disc)

### The Nice Function ###
def solve_rec(board, n, start, end, aux, spacing):
	if n == 0:
		return

	solve_rec(board, n-1, start, aux, end, spacing)

	print("MOVE DISC FROM POLE {} TO {}".format(start + 1, end + 1))
	board.move_disc(start, end)
	print(board)

	solve_rec(board, n-1, aux, end, start, spacing)

def solve_hanoi(n):
	board = Board(n)
	print("TOWERS OF HANOI - {} DISCS".format(n))
	print(board)
	solve_rec(board, n, 0, 2, 1, n)


		
