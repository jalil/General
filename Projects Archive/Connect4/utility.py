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
				for dir in lstDirs:
					dirUtil = node.mod_match_in_direction(i,j,dir[0],dir[1])
					if dirUtil == 2:
						self.two_score += 1
					elif dirUtil == 3:
						self.three_score += 1
					elif dirUtil == 4:
						self.
											
		if node.nodeplayer != utilityplayer:
			

		# The match_in_direction function is very helpful here.  You will need to
		# loop through positions, adding up the score for various three or two in a
		# rows for each player.

		# TODO: write me