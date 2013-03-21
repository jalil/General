from game import *
from minimax import *

game1 = ConnectFour()
player1 = Human(1)
choice = raw_input("Which test would you like to do?\n1. Human v. Human\n2. Human v. Random\n3. Test victory conditions\n4. Human v. Human with the ability to print out Minimax properties")

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

