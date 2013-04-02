class Player
	attr_accessor :pnum

	def initialize(pnum)
		@pnum = pnum
	end

	def playturn!(tictactoe)
		puts "Hello player #{self.pnum}!\n The board is as follows!"
		tictactoe.printBoard()
		while 1
			puts "Give me a row!"
			row = gets.chomp().to_i
			puts "Give me a col!"
			col = gets.chomp().to_i
			
			if tictactoe.empty?(row,col) == 0
				puts "That cell is occupied. Try again!"
			else 
				tictactoe.placeVal!(row,col,self.pnum)
				break
			end
		end
	end
end

class Game
	attr_accessor :turn, :p1, :p2, :game, :n

	def initialize()
		@game = nil
		@p1 = Player.new(1)
		@p2 = Player.new(2)
		@turn = 1
	end

	def play!()
		puts "Welcome to the Ruby NxN Tic Tac Toe game!\nPlease give me the N value for the number of columns and rows: "
		@game = TicTacToe.new(gets.chomp().to_i)
		while 1
			if self.turn % 2 == 1
				self.p1.playturn!(self.game)
			else
				self.p2.playturn!(self.game)
			end

			if self.game.isOver?() != 0 or self.game.isfull?() == 1
				print "Player #{self.game.isOver?()} has won!"
				break
			end
		
			self.turn += 1
		end
	end			
end

class TicTacToe
	attr_accessor :board, :n
	
	def initialize(n)
		@board = []
		@n = n
		for i in (0..n - 1)
			lstRow = []
			for j in (0..n-1)
				lstRow.push(0)
			end
			self.board.push(lstRow)
		end
	end

	def empty?(i,j)
		if self.board[i][j] == 0
			return 1
		else
			return 0
		end
	end

	def isfull?()
		for i in (0..self.n - 1)
			for j in (0..self.n - 1)
				if self.board[i][j] == 0
					return 0
				end
			end
		end
		return 1
	end

	def placeVal!(i,j, pnum)
		self.board[i][j] = pnum
	end	

	def printBoard()
		for i in (0..self.n - 1)
			outStr = "|"
			for j in (0..self.n - 1)
				if self.board[i][j] == 0
					outStr = outStr + "   |"
				elsif self.board[i][j] == 1
					outStr = outStr + " X |"
				elsif self.board[i][j] == 2
					outStr = outStr + " O |"
				end
			end
			puts "-" * ((self.n * 4) + 1)
			puts "#{outStr}"
		end
		puts "-" * ((self.n * 4) + 1)
	end
	
	def isOver?()
		outcomes = [0,0,0]
		outcomes[0] = self.vertVic?()
		outcomes[1] = self.horVic?()
		outcomes[2] = self.diagVic?()
		
		for i in (0..2)
			if outcomes[i] != 0
				return outcomes[i]
			end
		end
		return 0
	end	

	def vertVic?()
		for j in (0..self.n - 1)
			base = self.board[0][j]
			for i in (0..self.n - 1)
				if self.board[i][j] != base or base == 0
					break
				elsif self.board[i][j] == base and i == (self.n - 1)
					return base
				end
			end
		end
		return 0
	end
	
	def horVic?()
		for i in (0..self.n - 1)
			base = self.board[i][0]
			for j in (0..self.n - 1)
				if self.board[i][j] != base or base == 0
					break
				elsif self.board[i][j] == base and j == (self.n - 1)
					return base
				end
			end
		end
		return 0
	end

	def diagVic?()
		base = self.board[0][0]
		if base == 0
			return 0
		end

		for i in (0..self.n - 1)
			if self.board[i][i] != base or base == 0
				break
			elsif self.board[i][i] == base and i == (self.n - 1)
				return base
			end
		end
		
		base = self.board[self.n - 1][self.n - 1]
		if base == 0
			return 0
		end

		for i in (self.n - 1..0)
			if self.board[i][i] != base or base == 0
				break
			elsif self.board[i][i] == base and i == (self.n - 1)
				return base
			end
		end
		return 0	
	end
end


agame = Game.new()
agame.play!()
