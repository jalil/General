from game import *

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
		for i in range(len(copyfrom.board)):
			row = []
			for j in range(len(copyfrom.board[i])):
				row.append(copyfrom.board[i][j])
			node.board.append(row)
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
		node.parent = parent
		#set node.nodePlayer to opposite of parent
		if parent.nodePlayer == 1:
			node.nodePlayer = 2
		else:
			node.nodePlayer = 1
			
		#set node.from_parent_column
		node.from_parent_column = playcolumn
		
		#copy board from parent
		node.board = []
		for i in range(len(parent.board)):
			row = []
			for j in range(len(parent.board[i])):
				row.append(parent.board[i][j])
			node.board.append(row)		
		
		#print ("**************board memory locs*****************")
		#print id(node.board)
		#print id(parent.board)
		
		#make play in playcol
		node.play_turn(node.nodePlayer, playcolumn)
		
		
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