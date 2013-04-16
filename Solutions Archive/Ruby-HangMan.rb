def main()
	print "Welcome to a game of hangman!\nPlease type in a word that another player will guess!\n->"
	game = Hangman.new(gets.chomp())
	
	while game.isOver() == false
		game.printHangman()
		print "WORD TO GUESS:\n#{game.displayWord}\n\nAVAILABLE LETTERS:\n#{game.charsToGuess}\n\nWhat letter would you like to guess next?\n->"
		guess = gets.chomp()
		game.updateDisplayedWord(guess)
		game.updateCharsToGuess(guess)
		puts "After your guess of #{guess} the word you have to guess is #{game.displayWord}. You have #{5 - game.tries} tries left before you hang."
	end
end
		

class Hangman
	attr_accessor :word, :displayWord, :charsToGuess, :tries
	def initialize(word)
		@word = word
		@displayWord = "-" * self.word.length	
		@charsToGuess = "abcdefghijklmnopqrstuvwxyz"
		@tries = 0
	end
	
	def isOver()
		if self.displayWord == self.word
			puts "You win!"
			true
		elsif tries == 6
			puts "You lose!"
			self.printHangman()
			true
		else
			false
		end
	end

	def letterMatches(c)
		lstMatches = []
		for i in (0..self.word.length - 1)
			if self.word[i] == c
				lstMatches.push(i)
			end
		end
		return lstMatches
	end

	def updateCharsToGuess(c)
		idx = self.charsToGuess.index(c)
		if idx == 0
			self.charsToGuess = self.charsToGuess[1..self.charsToGuess.length - 1]
		elsif idx == self.charsToGuess.length - 1
			self.charsToGuess = self.charsToGuess[0.. self.charsToGuess.length - 2]
		else
			self.charsToGuess = self.charsToGuess[0..idx - 1] + self.charsToGuess[idx + 1..self.charsToGuess.length - 1]
		end
	end

	def printHangman()
		puts "    ______"
		puts "    |     |"

		if self.tries > 0
			puts "    0     |"
		else
			puts "          |"
		end

		if self.tries > 3 
			puts "   /|\\    |"

		elsif self.tries > 2
			puts "   /|     |"
		elsif  self.tries > 1
			puts "    |     |"
		else
			puts "          |"
		end

		if self.tries == 6
			puts "   / \\    |"
		elsif self.tries > 4
			puts "   /      |"
		else
			puts "          |"
		end
		
		puts "-----------"
	end		
	
	def updateDisplayedWord(c)
		lstMatches = self.letterMatches(c)
		if lstMatches.length != 0
			for i in lstMatches
				self.displayWord[i] = c
			end
		else
			self.tries += 1
		end
	end
	
end

main()
