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

	def getFullCols(self):
		lstFull = []
		for i in range(0, 7):
			if self.board[5][i] != None:
				lstFull.append(i)
		return lstFull

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
		while 1:
			col = random.randint(1,6)
			if col not in board.getFullCols():
				break
		board.play_turn(self.playernum, col)
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
				fullCols = board.getFullCols()
				if len(col) == 1 and col in '1234567890' and int(col) not in fullCols:
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

class Utility(object):
	def compute_utility(self, node, utilityplayer):
			"""
			Computes the utility of node with positive values good for utilityplayer
			and negative values good for the other player.
			"""
			pass

class SimpleUtility(Utility):
	def __init__(self, three_score, two_score):
		self.three_score = three_score
		self.two_score = two_score

	def compute_utility(self, node, utilityplayer):
		"""
		Computes the utility of the node, using the following rules.

		* If utilityplayer has won, the score is 1,000,000
		* If utilityplayer has lost, the score is -1,000,000
		* Award self.three_score points for each three in a row and self.two_score
		points for each two in a row for utilityplayer.
		* Award -self.three_score points for each three in a row and -self.two_score points
		for each two in a row for the other player.
		* Finally, award one point if node.nodeplayer equals utilityplayer (it is currently
		utilityplayer's move), otherwise award -1 points.

		This function should only be called on a leaf.
		"""
		#utilityVal will hold the final utility for the board and will be returned to the node
		utilityVal = 0

		lstDirs = [(-1,0),(1,0),(0,1),(0,-1),(1,1),(-1,-1),(-1,1),(1,-1)]		
		for i in range(6):
			for j in range(7):
				cellPlayer = node.get_position(i,j)
				if cellPlayer != None:
					for dir in lstDirs:
						dirUtil = node.mod_match_in_direction(i,j,dir[0],dir[1])
						if cellPlayer == utilityplayer:
							if dirUtil == 2:
								utilityVal += self.two_score
							elif dirUtil == 3:
								utilityVal += self.three_score 
							elif dirUtil == 4:
								utilityVal = 1000000
						elif cellPlayer != utilityplayer:
							if dirUtil == 2:
								utilityVal -= self.two_score
							elif dirUtil == 3:
								utilityVal -= self.three_score
							elif dirUtil == 4:
								utilityVal = -1000000
		if utilityplayer == node.nodePlayer:
			utilityVal += 1
			
		return utilityVal
class MinimaxNode(ConnectFour):

	@staticmethod
	def init_root(copyfrom, nodeplayer):
		"""
		Creates a new instance of the MinimaxNode class, with the board state copied
		from the copyfrom object, which is an instance of the ConnectFour class.  

		Also, create two properties:
		* a nodeplayer property, storing the fact that this node is a play for nodeplayer.
		* a from_parent_column property set to None (see below).  This marks that the
		node did not come from a parent.

		This method should only be used to create the root of the game tree from
		the current board state.
		"""
		node = MinimaxNode()
		
		#Copy board in copyfrom -> node.curBoard
		node.board = []
		for row in range(len(copyfrom.board)):
			curRow = copyfrom.board[row]
			node.board.append(curRow)
		
		#set node.nodePlayer of root	
		node.nodePlayer = nodeplayer
		
		#initialize from_parent_column to None as this is for the root
		node.from_parent_column = None
			
		return node

	@staticmethod
	def init_child(parent, playcolumn):
		"""
		Creates a MinimaxNode by copying the board state from parent (which is an instance
		of MinimaxNode) and then making a play in playcolumn (which is an integer
		between 0 and 6).

		Also, create two properties:
		* nodeplayer property, which is the opposite of the parent nodeplayer, representing
		that the child is now a play for the other player.
		* from_parent_column property, which stores the playcolumn parameter.  This is used to
		know which column was played to to get from the parent to the child, and is used
		at the very end to know which play to make.
		"""
		node = MinimaxNode()
		node.value = 0
		
		#copy board from parent
		node.board = []
		for row in range(len(parent.board)):
			curRow = parent.board[row]
			node.board.append(curRow)
		
		#set node.nodePlayer to opposite of parent
		if parent.nodePlayer == 1:
			node.nodePlayer = 2
		else:
			node.nodePlayer = 1
			
		#set node.from_parent_column
		node.from_parent_column = playcolumn
		
		return node

	def compute_children(self):
		"""
		Computes the list of children of this node and stores it in a property called children.
		This method only creates the immediate children (this is lazy evaluation).
		"""
		#remove all empty rows from possibilities list
		lstPossible = [0,1,2,3,4,5,6]
		for j in range(7):
			if self.board[5][j] != None:
				lstPossible.remove(j)

		#initialize children for each available column
		self.children = []		
		for val in  lstPossible:
			self.children.append(self.init_child(self, val))
		

	def set_minimax_value(self, val):
		"""
		Stores the minimax value for this node.  This represents the largest utility
		that can be forced on a leaf no matter how the enemy plays.
		"""
		self.value = val

	def get_minimax_value(self):
		"""
		From this node, it is possible to reach a leaf with this utility.
		"""
		return self.value

class MinimaxPlayer(Player):
	def __init__(self, playernum, ply_depth, utility):
		super(MinimaxPlayer, self).__init__(playernum)
		self.ply_depth = ply_depth
		self.utility = utility

	def reversePlayer(self):
		if self.playernum == 1:
			return 2
		else:
			return 1

	def minimax(self, node, cur_depth):
		#consider cur_depth start at 0... odd == enemy even == friendly
		if cur_depth == self.ply_depth:
			node.set_minimax_value(self.utility.compute_utility(node, node.nodePlayer))
		else:	
			node.compute_children()
			lstOutcomes = []
			for child in node.children:
				self.minimax(child, cur_depth + 1)
				lstOutcomes.append(child.get_minimax_value)
			
			if cur_depth % 2 == 0:
				return max(lstOutcomes)
			else:
				return min(lstOutcomes)
			

	def play_turn(self,board):
		root = MinimaxNode.init_root(board, self.playernum)
		self.minimax(root, 0)
		largestUtil = -1000000000
		childToPlay = None
		for child in root.children:
			if child.get_minimax_value() > largestUtil:
				largestUtil = child.get_minimax_value()
				childToPlay = child
		board.play_turn(self.playernum, childToPlay.from_parent_column)
		
game1 = ConnectFour()
player1 = Human(1)
choice = raw_input("Which test would you like to do?\n1. Human v. Human\n2. Human v. Random\n3. Test victory conditions\n4. Human v. Human with the ability to print out Minimax properties\n5. Human v. Human with the goal of printing utility of a given board state\n6. Human v. Minimax player")

if choice == '1':
	player2 = Human(2)
	play_game(game1,player1,player2)
elif choice == '2':
	player2 = RandomPlayer(2)
	play_game(game1,player1,player2)
elif choice == '3':
	games = []
	for x in range(5):
		games.append(ConnectFour())
		games[x].random_unit_test()
		games[x].print_board()
		print games[x].is_game_over()
elif choice == '4':
	player2 = Human(2)
	lstMoves = raw_input("Input a space delimited list of column moves: ")
	lstMoves = lstMoves.split(' ')
	for i in range(len(lstMoves)):
		if i % 2 == 1:
			game1.play_turn(1,int(lstMoves[i]))
		else:
			game1.play_turn(2,int(lstMoves[i]))
	player = len(lstMoves) % 2 
	if player != 1:
		player = 2
	
	game1.print_board()
	mm = MinimaxNode()
	rootMM = mm.init_root(game1, player)
	rootMM.compute_children()
	print "The number of children computed is %d" %len(rootMM.children)
	
elif choice == '5':
		player2 = Human(2)
		lstMoves = raw_input("The utility value is representative of player 1 whose turns are represented by all odd index inputs\nInput a space delimited list of column moves:")
		lstMoves = lstMoves.split(' ')
		for i in range(len(lstMoves)):
			if i % 2 == 1:
				game1.play_turn(1,int(lstMoves[i]))
			else:
				game1.play_turn(2,int(lstMoves[i]))
			
		game1.print_board()
		mm = MinimaxNode()
		rootMM = mm.init_root(game1, 1)
		util = SimpleUtility(5,1)
		print util.compute_utility(rootMM, 1)
		
elif choice == '6':
	player2 = MinimaxPlayer(playernum=2,ply_depth=4, utility = SimpleUtility(5,1))
	play_game(game1, player1, player2)
	
		