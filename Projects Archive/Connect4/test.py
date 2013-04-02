from game import *
from minimax import *
from utility import *
from minimaxplayer import *



def play_game_mod(board, player1, player2):
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
					return board.is_game_over(), turn
					break
			else:
				turn += 1
	





game1 = ConnectFour()
player1 = Human(1)
choice = raw_input("Which test would you like to do?\n1. Human v. Human\n2. Human v. Random\n3. Test victory conditions\n" +
					"4. Human v. Human with the ability to print out number of children computed\n5. Human v. Human with the goal of printing utility" +
					"of a given board state\n6. Human v. Minimax player\n7. Minimax v. Random player\n8. Minimax player v. Minimax player\n" +
					"9. Collect stats on Random v. Minimax")

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
	player1 = MinimaxPlayer(playernum=1,ply_depth=4, utility = SimpleUtility(5,1))
	player2 = MinimaxPlayer(playernum=2, ply_depth=2, utility = SimpleUtility(5,1))
	play_game(game1, player1, player2)
	
elif choice == '7':
	player1 = RandomPlayer(1)
	player2 = MinimaxPlayer(playernum=2,ply_depth=2,utility = SimpleUtility(5,1))
	play_game(game1,player1,player2)

elif choice == '8':
	player1 = MinimaxPlayer(playernum=1,ply_depth=4,utility = SimpleUtility(5,1))
	player2 = MinimaxPlayer(2,2,WithColumnUtility(5,1, 5))
	
	play_game(game1,player1,player2)
	
elif choice == '9':
	player2 = MinimaxPlayer(playernum=2,ply_depth=2 ,utility = WithColumnUtility(5,1,4))
	play_game(game1,player1,player2)
				