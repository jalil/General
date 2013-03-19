import random

class ConnectFour(object):
	def __init__(self):
		self.board = []
        	for i in range(6):
			self.board.append([])
			for j in range(7):
				self.board[i].append(None)
#		for i in range(6):
#			print 'row'
#			for j in range(7):
#				print "col"


	def get_position(self, row, column):
		"""
		Returns either None or an integer 1 or 2 depending on which player
		is occupying the given row or column.  Row is an integer between 0
		and 5 and column is an integer between 0 and 6.
		"""
		assert row >= 0 and row < 6 and column >= 0 and column < 7

		if self.board[row][column] != None:
			if self.board[row][column] == 'X':
				return 1
			elif self.board[row][column] == 'O':
				return 2
		else:
			return None

	def match_in_direction(self, row, column, step_row, step_col):
		"""
		Counts how many chips, starting from (row, column) and moving in the
		direction (step_row, step_col), match the player who occupies (row,column).

		Arguments:
		row: an integer between 0 and 5
		column: an integer between 0 and 6
		step_row: an integer, either -1, 0, or 1
		step_col: an integer, either -1, 0, or 1

		This function first checks which player occupies (row,column).  If no
		player occupies this position, 0 is returned.  Otherwise, the function
		then continues checking (row + step_row, column + step_column), (row +
		2*step_row, column + 2*step_column), and so forth, continuing until a
		location is either empty, the board edge is reached, or a position is
		occupied by an opposing player.  The function then returns how many
		chips (including the first chip at (row, column), match.  Note if the
		function returns 4 or more, this is a winning position. 
		"""
        	assert row >= 0 and row < 6 and column >= 0 and column < 7
		assert step_row != 0 or step_col != 0 # (0,0) gives an infinite loop

		intPlayer = 0

        	if self.board[row][column] != None:
			if self.board[row][column] == 'X':
				intPlayer = 1
			elif self.board[row][column] == 'O':
				intPlayer = 2
		else:
			return None

		counter = 1
		loop = True
		while loop == True:
			if counter == 4:
				return counter
			if (row + (counter * step_row) <= 5 and row + (counter * step_row) >= 0) and (column + (counter * step_col) <= 6 and column + (counter * step_col) >= 0):
				if self.get_position((row + (step_row * counter)), (column + (step_col * counter))) == intPlayer:
					counter += 1
				else:
					counter = 1
			else:
				loop = False
		return counter

	def genDiag(self, lBound, uBound, pORm, vORh, colStart = 0):
	#Generalized diagonal test -- child of diagTest
	#lBound == lower bound of rows
	#uBound == upper bound of rows
	#pORm == char 'p' <- (plus == asc diags), char'm' <- (minus == desc diags)
	#vORh == char 'v' or 'h': if 'v' then iterate over rows, elif 'h' iterate over columns

		if vORh == 'v':
			for i in range(lBound, uBound):
				repeatCount = 0
				repeatChar = ''
				x = colStart # <- depth of diag
				while x < i:
					if self.board[i - x][x] != None:
						if repeatChar == '':
							repeatChar = self.board[i-x][x]
							repeatCount = 1
						elif self.board[i - x][x] == repeatChar:
							repeatCount += 1
						elif self.board[i - x][x] != repeatChar:
							repeatChar = self.board[i - x][x]
							repeatCount = 1
						if repeatCount == 4:
							return self.get_position(i - x, x)
					else:
						if float(x) / i > 0.6 and i != 0:
							break
						else:
							repeatChar = ''
							repeatCount = 0
					if pORm == 'p':
						x += 1
					else:
						x -= 1
			return None
		elif vORh == 'h':
			for j in range(lBound, uBound):
				repeatCount = 0
				repeatChar = ''
				y  = colStart
				while y < 6:
					if self.board[y][j] != None:
						if repeatChar == '':		
							repeatChar = self.board[y][j]
							repeatCount = 1
						elif self.board[y][j] == repeatChar:
							repeatCount +=  1
						elif self.board[y][j] != repeatChar:
							repeatChar = self.board[y][j]
							repeatCount = 1
		
						if repeatCount == 4:
							return self.get_position(y, j)
					else:
						if float(y) / j > 0.6 and j != 0:
							break
						else:
							repeatChar = ''
							repeatCount = 0
					if pORm == 'p':
						y += 1
					else:
						y -= 1
			return None


	def diagTest(self):
	#Notes: Asc-Asc Diagonals spanning board
	#       3 =< row =< 5 are valuable
	#	rows 0 -> 2 are worthless as max len < 4
	#	1 =< col =< 3 are valuable
	#	cols 0, 4 -> 6 are worthless as max len < 4
	#Notes: Desc-Desc Diagonals spanning board
	#	
	
		#Asc-Asc Diagonals paired tests:
		pOut1 = self.genDiag(3,6,'p','v', 0) # <- optimized start location for (0,0) vertical portion of grid
		pOut2 = self.genDiag(1,4, 'p', 'h', 0) # <- optimized start location for (6,7) horizontal portion of grid
		print self.genDiag(3,6,'m','v',6)
		#dOut2 = 

		if pOut1 != None and pOut2 != None:
			return pOut1
		elif pOut1 != None:
			return pOut1
		elif pOut2 != None:
			return pOut2
		else:
			return None

		
	def vertTest(self):
		for j in range(7):
			repeatCount = 0 
			repeatChar = ''
			for i in range(6):
				if self.board[i][j] != None:
					if repeatChar == '':
						repeatChar = self.board[i][j]
						repeatCount = 1
					elif self.board[i][j] == repeatChar:
						repeatCount += 1
					elif self.board[i][j] != repeatChar:
						repeatChar = self.board[i][j]
						repeatCount = 1
					if repeatCount == 4:
						return self.get_position(i, j)
				else: #If streak not found and none found in col then skip col
					break

		return None

	def horTest(self):
		for i in range(6):
			repeatCount = 0
			repeatChar = ''
			for j in range(7):
				if self.board[i][j] != None:
					if repeatChar == '':
						repeatChar = self.board[i][j]
						repeatCount = 1
					elif self.board[i][j] == repeatChar:
						repeatCount += 1
					elif self.board[i][j] != repeatChar:
						repeatChar = self.board[i][j]
						repeatCount = 1
					if repeatCount == 4:
						return self.get_position(i, j)
				else: 
					if j > 3: #These tests would be unecessary after finding a None
						break
					else:
						repeatChar = ''
						repeatCount = 0

		return None
					

	def is_game_over(self):
		"""
		Returns None if the game is not yet over, or 1 or 2 depending
		on if player 1 or 2 has won the game.
		"""
		# Note, match_in_direction is very helpful.

		for i in range(6):
			for j in range(7): 
				if i > 2:
					if self.match_in_direction(i,j,1,0) >= 4:
						return self.get_position(i,j)
				else:
					if self.match_in_direction(i,j,-1,0) >= 4:
						return self.get_position(i,j)

				if j > 2:
					if self.match_in_direction(i,j,0,1) >= 4:
						return self.get_position(i,j)
				else:
					if self.match_in_direction(i,j,0,-1) >= 4:
						return self.get_position(i,j)

				if i > 2 and j > 2:
					if self.match_in_direction(i,j,-1,-1) >= 4:
						return self.get_position(i,j)
				else:
					if self.match_in_direction(i,j,1,1) >= 4:
						return self.get_position(i,j)
			
				if self.match_in_direction(i,j,-1,1) >= 4 or self.match_in_direction(i,j,1,-1) >= 4:
					return self.get_position(i,j)							
		return None
			
						


	def play_turn(self, player, column):
		""" Updates the board so that player plays in the given column.
		player: either 1 or 2
		column: an integer between 0 and 6
		"""
		assert player == 1 or player == 2
		assert column >= 0 and column < 7

		for i in range(0,6, 1):
			if self.board[i][column] != None:
				pass
			else:				
				if player == 1:
					self.board[i][column] = 'X'
					break
				else:
					self.board[i][column] = 'O'
					break

	def print_board(self):
		print "-" * 29
		print "| 0 | 1 | 2 | 3 | 4 | 5 | 6 |"
		print "-" * 29
		for row in range(5,-1,-1):
			s = "|"
			for col in range(7):
				p = self.get_position(row, col)
				if p != None:
					if p == 1:
						s += " x |"
					elif p == 2:
						s += " o |"
				else:
					s += "   |"
					# This is impossible if the code is correct, should never occur.
					#s += " ! |"
			print s
			print "-" * 29


	def random_unit_test(self):
		for i in range(6):
			for j in range(7):
				r = random.randint(1,2)
				if r == 1:
					self.board[i][j] = 'X'
				else:
					self.board[i][j] = 'O'

game = ConnectFour()
game.print_board()
game.random_unit_test()
game.print_board()
print game.vertTest()
print game.horTest()
print game.diagTest()
