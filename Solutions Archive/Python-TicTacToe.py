#-------------------------------------------------------------------------------
# Name:        Tic tac tow
# Purpose:     It's a game!
#
# Author:      Braden Lenz
#
# Created:     20/03/2013
# Copyright:   (c) Windows User 2013
# Licence:     GNU GPL v3
#-------------------------------------------------------------------------------


class TicTacToe():
	def __init__(self):
		
		#initialize the grid
		self.grid = []
		for i in range(3):
			row = []
			for j in range(3):
				row.append(None)
			self.grid.append(row)
	def check_position(self,row,col):
		if self.grid[row][col] != None:
			if self.grid[row][col] == 'X':
				return 1
			else:
				return 2
		else:
			return None
	def match_direction(self,i,j,addRow, addCol):
		#lstReps holds the repeatChar at idx == 0 and the number of repeats at idx == 1
		lstReps = [self.check_position(i,j), 1]
		
		if lstReps[0] != None:
			for k in range(2):
				if i + addRow > 2 or j + addCol > 2:
					return None
				else:
					if self.check_position(i + addRow, j + addCol) != lstReps[0]:
						return None
					elif self.check_position(i + addRow, j + addCol) == lstReps[0]:
						lstReps[1] += 1
						#if loop completed and execution reached this pos then there is a victor
						if lstReps[1] == 3:
							return lstReps[0]
		else:
			return None

					
	def player_turn(self,row,col, playernum):
			if self.grid[row][col] != None:
				return None
			else:
				if playernum == 1:
					self.grid[row][col] = 'X'
				else:
					self.grid[row][col] = 'O'
				return 1

	def is_game_over(self):
		lstWinPoss = [(1,1),(-1,-1),(-1,1),(1,-1),(1,0),(0,1),(-1,0),(0,-1)] 
		for i in range(3):
			for j in range(3):
				for dirSet in lstWinPoss:
					matchOut = self.match_direction(i,j, dirSet[0],dirSet[1])
					if matchOut != None:
						return matchOut
				
	def print_board(self):
		print "-" * 13
		for row in range(3):
			s = "|"
			for col in range(3):
				p = self.check_position(row, col)
				if p != None:
					if p == 1:
						s += " x |"
					elif p == 2:
						s += " o |"
				else:
					s += "   |"
			print s
			print "-" * 13

class Player():
	def __init__(self, playernum):
		self.playernum = playernum
	def play_turn(self):
		pass

class Human(Player):
	def __init__(self, playernum):
		self.playernum = playernum
	def play_turn(self, grid):
		print("Hey, player %d! It's your turn!\n" %self.playernum)
		grid.print_board()
		row = int(raw_input("\n\nInput the row you would like to input: "))
		col = int(raw_input("\nInput the col you would like to input: "))
		grid.player_turn(row,col,self.playernum)
		grid.print_board()


def playGame():
	p1 = Human(1)
	p2 = Human(2)
	game = TicTacToe()
	counter = 1
	while True:
		if counter % 2 == 1:
			p1.play_turn(game)
		else:
			p2.play_turn(game)
		if game.is_game_over() != None:
			print("Player %d has won!"%(counter % 2))
			break
		counter += 1


playGame()
