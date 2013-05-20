import random

class RockPaperScissors:
	def __init__(self, n):
		self.n = n
		self.p1 = 0
		self.p2 = 0

	def evalMoves(self,m1, m2):
		deltaMoves = m1 - m2
		if deltaMoves > 0:
			if deltaMoves == 2:
				return 2
			else:
				return 1
		elif deltaMoves < 0:
			if deltaMoves == -2:
				return 1
			else:
				return 2
		else:
			return 0

	def playRound(self):
		moves = ['Rock', 'Paper', 'Scissors']		

		print "\nCurrent Scores:\nHuman Player --> " + str(self.p1) + "\nComputer Player --> " + str(self.p2)

		mP1 = int(raw_input("\nChoose a move:\n1 -- Rock\n2 -- Paper\n3 -- Scissors\nWhich would you like\n  --> "))
		mP2 = random.randrange(1,4)
		
		print "Human played a " + str(moves[mP1 - 1]) + " and the computer played a " + str(moves[mP2 - 1])		

		outcome = self.evalMoves(mP1, mP2)
				
		if outcome == 0:
			print "This round ended in a draw since both players had the same move"
		elif outcome == 1:
			self.p1 += 1
			print "Human player round!"
		else:
			self.p2 += 1
			print "Computer player the round!"

	def playGame(self):
		print "Welcome to the Rock-Paper-Scissors game!"
		while self.p1 < self.n and self.p2 < self.n:
			self.playRound()
		
		if self.p1 == self.n:
			print "Congratulations human! You beat skynet!"
		else:
			print "Sorry man. The computer won."

def main():
	n = int(raw_input("How many rounds would you like the game-ending condition to be out of?\n  --> "))
	game = RockPaperScissors(n)
	game.playGame()

main()
