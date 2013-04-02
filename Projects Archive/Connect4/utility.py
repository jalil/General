from game import *
from minimax import *

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
							elif dirUtil >= 4:
								utilityVal += 1000000
						elif cellPlayer != utilityplayer:
							if dirUtil == 2:
								utilityVal -= self.two_score
							elif dirUtil == 3:
								utilityVal -= self.three_score
							elif dirUtil >= 4:
								utilityVal += -10000000
		
		#changed to node.parent.nodePlayer because it more accurately reflects the move advantage
		if utilityplayer == node.parent.nodePlayer:
			utilityVal += 1
		else:
			utilityVal -= 1
		return utilityVal



class WithColumnUtility(SimpleUtility):
	def __init__(self, three_score, two_score, column_scores):
		self.three_score = three_score
		self.two_score = two_score
		self.column_scores = column_scores

	def compute_utility(self,node,utilityplayer):
		score = super(WithColumnUtility, self).compute_utility(node, utilityplayer)
		
		for i in range(6):
			cellPlayer = node.get_position(i,3)
			if cellPlayer != None:
				if cellPlayer == utilityplayer:
					score += self.column_scores
				else:
					score -= self.column_scores
		return score