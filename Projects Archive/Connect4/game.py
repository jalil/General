import random

class ConnectFour(object):
	def __init__(self):
		self.board = []
		for i in range(6):
			self.board.append([])
			for j in range(7):
				self.board[i].append(None)

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

	def mod_match_in_direction(self, row, column, step_row, step_col):
		"""
		This version of match_in_direction will return the longest possible streak <= 4

		This version is necessary as the original function is being utilized to exclusively
		check for victory conditions.		
		"""
		assert row >= 0 and row < 6 and column >= 0 and column < 7
		assert step_row != 0 or step_col != 0 # (0,0) gives an infinite loop

		if self.get_position(row,column) != None:
			c = self.get_position(row,column)
			i = row
			j = column
			streak = 1
			for k in range(3):
				if i + step_row > 5 or j + step_col > 6 or i + step_row < 0 or j + step_col < 0:
					return streak
				
				if self.get_position(i + step_row,j + step_col) != c:
					return streak
				elif self.get_position(i + step_row, j + step_col) == c:
					streak += 1
				
				i += step_row
				j += step_col
				
			return streak
		
		else:
		
			return 1

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

		if self.get_position(row,column) != None:
			c = self.get_position(row,column)
			i = row
			j = column
			for k in range(3):
				if i + step_row > 5 or j + step_col > 6 or i + step_row < 0 or j + step_col < 0:
					break
				
				if self.get_position(i + step_row,j + step_col) != c:
					break
				elif self.get_position(i + step_row, j + step_col) == c and k == 2:
					return c
				
				i += step_row
				j += step_col
		else:
			return None

	def is_game_over(self):
		"""
		Returns None if the game is not yet over, or 1 or 2 depending
		on if player 1 or 2 has won the game.
		"""
		lstDirs = [(-1,0),(1,0),(0,1),(0,-1),(1,1),(-1,-1),(-1,1),(1,-1)]

		for i in range(6):
			for j in range(7):
				for dir in lstDirs:
					if self.match_in_direction(i, j, dir[0], dir[1]) != None:
						return self.match_in_direction(i,j,dir[0], dir[1])

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
					
class Player(object):
    def __init__(self, playernum):
        self.playernum = playernum

    def play_turn(self, board):
        """
        This method is passed an instance of ConnectFour.  It should examine the board
        (using methods on the ConnectFour class) and eventually call board.play_turn and return.
        """
        pass
    
class RandomPlayer(Player):
	def __init__(self, playernum):
		self.playernum = playernum
		
	def play_turn(self, board):
		print("It is random player number %d's turn!\n" %self.playernum)
		print("*" * 9) + "Before Turn" + ("*" * 9)
		board.print_board()
		board.play_turn(self.playernum, random.randint(1,6))
		print("*" * 9) + "After Turn" + ("*" * 9)
		board.print_board()
class Human(Player):
	def __init__(self,playernum):
		self.playernum = playernum
		
	def play_turn(self, board):
			print("It is your turn player number %d!\n" %self.playernum)
			print ("*" * 9) + "Before Turn" + ('*' * 9)
			board.print_board()
			isLoop = True
			while isLoop == True:
				col = raw_input("Type in the column number you would like to put your chip in: ")
				if len(col) == 1 and col in '1234567890':
					col = int(col)
					print ("*" * 9) + "After Turn" + ("*" * 9)
					board.play_turn(self.playernum, col)
					isLoop = False
				else:
					print "That input was invalid. Remember that only a value between 0 and 9 may be input"
			board.print_board()
			
def play_game(board, player1, player2):
	print "Welcome to the Connect 4 game!\n"
	isDone = False
	turn = 1
	while isDone == False:
		print "TURN %d:\n" %turn
		if turn % 2 == 1:
			player1.play_turn(board)
			
		else:
			player2.play_turn(board)
			
		if board.is_game_over() != None:
				print("Player %d has won the game!\n" %board.is_game_over())
				break
		else:
			turn += 1

