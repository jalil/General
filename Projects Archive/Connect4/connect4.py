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

	def match_in_direction(self,row,col,srow,scol, uchar):
		if row + srow > 5 or col + scol > 6:
			return None
		
		if self.board[row + srow][col + scol] != None:
			if uchar == self.board[row + srow][col + scol]:
				return 1
			else:
				return 0
		else:
			return 'n'
		
	def checkDiag(self):
		lstOuts = []
		#Checking along the col = 0 rows
		for row in range(3, 6):
			repeatChar = 'X'
			repeatCount = 0
			rcounter = row
			ccounter = 0
			while ccounter <= row:
				out = self.match_in_direction(rcounter,ccounter,-1,1,repeatChar)
				if out == 1:
					repeatCount += 1
					lstOuts.append((rcounter,ccounter))
				elif out == 0:
					repeatChar = self.board[rcounter][ccounter]
					repeatCount = 1
				else:
					break
				if repeatCount == 4:
					print lstOuts
					return self.get_position(rcounter, ccounter)
				rcounter -= 1
				ccounter += 1
		
		#Checking along row = 5 cols
		'''for col in range(1,4):
			repeatChar = ''
			repeatCount = 1
			rcounter = 5
			
			while counter >= (counter - col): #i.e. col = 2 checks 5 grid coords
				out = self.match_in_direction(counter, col, -1, 1, self.board[counter][col])  
				if out == 1:
					repeatCount += 1
					lstOuts.append((counter,col))
				elif out == 0:
					repeatChar = self.board[counter][col]
					repeatCount = 1
				else:
					break
				if repeatCount == 4:
					print lstOuts
					return self.get_position(counter, col)

			counter -= 1'''
		return None

	def genDiag(self, lBound, uBound, intOp, colStart = 0):
	#Generalized diagonal test -- child of diagTest
	#lBound == lower bound of rows
	#uBound == upper bound of rows
	#pORm == char 'p' <- (plus == asc diags), char'm' <- (minus == desc diags)
	#vORh == char 'v' or 'h': if 'v' then iterate over rows, elif 'h' iterate over columns
		if intOp == 1:
			for i in range(lBound, uBound):
				repeatChar = 0
				repeatChar = 0
				x = 6
				y = 0
				while x >= 0:
					if self.board[i - y][x] != None:
						if repeatChar == '':
							repeatChar = self.board[i - y][x]
							repeatCount = 0
						elif self.board[i - y][x] == repeatChar:
							repeatCount += 1
						elif self.board[i - y][x] != repeatChar:
							repeatChar = self.board[i - y][x]
							repeatCount = 1
						if repeatCount == 4:
							return self.get_position(i - y, x)
					else:
						repeatChar = ''
						repeatCount = 0

					x -= 1
				return None




		elif intOp == 2:
			for i in range(3, 6):
				repeatCount = 0
				repeatChar = ''
				x = 0 # <- depth of diag
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
					x += 1
			return None
		elif intOp == 3:
			for j in range(1, 4):
				repeatCount = 0
				repeatChar = ''
				depth = 0
				rowStart = 6
				
				
				#self.board[rowStart - depth][colStart + depth]
				
				
				
				
				
				
				k = j
				y  = 0
				while y < 6 and k < 7:
					if self.board[y][k] != None:
						if repeatChar == '':		
							repeatChar = self.board[y][k]
							repeatCount = 1
						elif self.board[y][k] == repeatChar:
							repeatCount +=  1
						elif self.board[y][k] != repeatChar:
							repeatChar = self.board[y][k]
							repeatCount = 1
		
						if repeatCount == 4:
							return self.get_position(y, k)
					else:
						if float(y) / k > 0.6 and k != 0:
							break
						else:
							repeatChar = ''
							repeatCount = 0

					y += 1
					k += 1

			return None


		elif intOp == 4:
			for j in range(4, 7):
				repeatCount = 0
				repeatChar = ''
				y = 6
				y = 0
				while y >= 0:
					if self.board[i - y][x] != None:
						if repeatChar == '':
							repeatChar = self.board[i - y][x]
							repeatCount = 0
						elif self.board[i - y][x] == repeatChar:
							repeatCount += 1
						elif self.board[i - y][x] != repeatChar:
							repeatChar = self.board[i - y][x]
							repeatCount = 1
						if repeatCount == 4:
							return self.get_position(i - y, x)
					else:
						repeatChar = ''
						repeatCount = 0

					x -= 1
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
		print self.genDiag(3,6,2,0) # <- optimized start location for (0,0) vertical portion of grid
		print self.genDiag(1,4, 3,0) # <- optimized start location for (6,7) horizontal portion of grid
		print self.genDiag(3,6,1,6), 'minus'
		#dOut2 = 

#		if pOut1 != None and pOut2 != None:
#			return pOut1
#		elif pOut1 != None:
#			return pOut1
#		elif pOut2 != None:
#			return pOut2
#		else:
#			return None

		
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
print "\n\n\n\n\n\n\n\n\n\n"

agame = ConnectFour()
agame.play_turn(1,3)
for i in range(2):
	for j in range(7):
		if j % 2 == 0:
			agame.play_turn(1,j)
		else:
			agame.play_turn(2,j)
			
agame.play_turn(1,1)
agame.play_turn(2,1)
agame.play_turn(2,1)
agame.play_turn(1,1)
agame.play_turn(1,2)
agame.play_turn(2,2)
agame.play_turn(1,2)
agame.play_turn(1,3)
agame.play_turn(1,3)
agame.play_turn(1,4)
#agame.board(0,3) = 'X'
agame.play_turn(2,0)
agame.play_turn(1,0)
agame.print_board()
print agame.checkDiag()