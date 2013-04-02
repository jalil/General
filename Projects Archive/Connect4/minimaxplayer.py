from game import *
from utility import *
from minimax import *

class MinimaxPlayer(Player):
	def __init__(self, playernum, ply_depth, utility):
		super(MinimaxPlayer, self).__init__(playernum)
		self.ply_depth = ply_depth
		self.utility = utility

	def reversePlayer(self, playernum):
		if playernum== 1:
			return  2
		else:
			return 1
	def printMinimax(self, node, cur_depth):
		'''if node.from_parent_column != None:
			print "I am at depth %i and have a parent column of %i" %(cur_depth, node.from_parent_column)
		if cur_depth == self.ply_depth:
			print 'bottom', cur_depth, node.get_minimax_value(), node.from_parent_column
		else:
			if cur_depth % 2 == 0:
				print "friendly", cur_depth
			else:
				print "enemy", cur_depth
			print node.get_minimax_value()
			for child in node.children:
				#print(child.from_parent_column)
				self.printMinimax(child, cur_depth + 1)	
		'''
		#if node.from_parent_column != None:
		#	
		
		if cur_depth == 2:
			print ("DEPTH %d and COL %d and VAL %d") %(cur_depth, node.from_parent_column, node.value)
			node.print_board()
		if cur_depth == 3 and node.from_parent_column == 0:
			print ("DEPTH %d and COL %d and VAL %d") %(cur_depth, node.from_parent_column, node.value)
			node.print_board()			
		
		if cur_depth == self.ply_depth:
			return
		for child in node.children:
			self.printMinimax(child, cur_depth + 1)		
	def minimax(self, node, cur_depth):
		if cur_depth == self.ply_depth:
			return self.utility.compute_utility(node, self.playernum)
			
		else:
			if cur_depth == 0:
				node.nodePlayer = self.reversePlayer(node.nodePlayer)
				node.compute_children()
				node.nodePlayer = self.reversePlayer(node.nodePlayer)
				for child in node.children:
					child.set_minimax_value(self.minimax(child, cur_depth + 1))

			else:
				node.compute_children()
				for child in node.children:
					child.set_minimax_value(self.minimax(child, cur_depth + 1))
			
			if cur_depth % 2 == 0:		
				v = -9999999999
				for child in node.children:
					v = max(v, child.get_minimax_value())
				node.set_minimax_value(v)
				return v	
			else:
				v = 99999999999
				for child in node.children:
					v = min(v, child.get_minimax_value())
				node.set_minimax_value(v)
				return v

	
	'''
	def oneply(self,node):
		node.nodePlayer = self.reversePlayer(node.nodePlayer)
		node.compute_children()
		v = -9999999999
		for child in node.children:
			 child.set_minimax_value(self.utility.compute_utility(child, self.playernum))
			 child.print_board()
			 v = max(v, child.get_minimax_value())
		for child in node.children:
			if v == child.get_minimax_value(): 
				return child
	'''


	def play_turn(self,board):
		print("It is Minimax player's turn!")
		print("*********Before Turn*********")
		board.print_board()
		
		root = MinimaxNode.init_root(board, self.playernum)
		self.minimax(root, 0)
		
		val = -99999999
		for child in root.children:
			val = max(val, child.get_minimax_value())
		for child in root.children:
			if val == child.get_minimax_value():
				thechild = child
 		
 		#mKey = -10000000
 		#for key in dicChildren.iterkeys():
 		#	mKey = max(mKey, key)
 			
		#child = dicChildren[mKey]
		board.play_turn(self.playernum, thechild.from_parent_column)
		
		print("*********After Turn*********")
		board.print_board()
		#self.printMinimax(root, 0)
		