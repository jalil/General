class Player
	attr_accessor :playernum, :points
	def initialize(n)
		@playernum = n
		@points = 0
	end
	
	def playTurn(isGuessing, num = 0)
		if isGuessing == false
			print "This turn you will input the number to be guessed.\nChoose a number between 1 and 100\n->"
			return gets.chomp().to_i 
		else
			puts "You are guessing what the number is! Remember that it is a number between 1 and 100 and you get 5 tries to get the number correctly!"
			tries = 0
			while tries < 5
				print "Guess #{tries + 1}: "
				attempt = gets.chomp().to_i
				if attempt == num 
					puts "You correctly guessed the number! Great job!"
					return self.playernum
				elsif attempt > num
					puts "Your guess was too high!"
				elsif attempt < num 
					puts "Your guess was too low!"
				end
				tries += 1
			end
				
			puts "Sorry, you didn't correctly guess the number. It was #{num}."
			if self.playernum == 1
				return 2
			else
				return 1
			end
		end
	end
end

class Game
	attr_accessor :p1, :p2, :turn, :num

	def initialize()
		@p1 = Player.new(1)
		@p2 = Player.new(2)
		@turn = 1
		@num = 0
	end

	def play!()
		while 1
			puts "\nSCORE:\nPlayer 1: #{self.p1.points}\nPlayer 2: #{self.p2.points}\n"
			if self.turn % 2 == 0
				puts "\nPlayer 1: You will enter the number!"
				self.num = self.p1.playTurn(false)
				puts  ("\n" * 100)
				puts "\nPlayer 2: You will guess the number!"
				playerToInc = self.p2.playTurn(true, self.num)
			else 
				puts "\nPlayer 2: You will enter the number!"
				self.num = self.p2.playTurn(false)
				puts ("\n" * 100)
				puts "\nPlayer 1: You will guess the number!"
				playerToInc = self.p1.playTurn(true, self.num)
			end
					
			if playerToInc == 1
				self.p1.points += 1
			else
				self.p2.points += 1
			end
	
			if gameOver?() == true
				puts "Bye!"
				break
			end
			self.turn += 1		
			
		end
	end

	def gameOver?()
		if self.p1.points == 3 or self.p2.points == 3
			if self.p1.points == 3
				puts "Great job player 1! You won!"
			else
				puts "Great job player 2! You won!"
			end
			
			return true
		else
			return false
		end
	end
end

agame  = Game.new()
agame.play!()
