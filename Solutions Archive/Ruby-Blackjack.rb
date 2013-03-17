class Card
	attr_accessor :suit, :type, :val

	def initialize(suit, type)
		@suit = suit
		@type = type
		@val = evaluate(@type)
	end

	def evaluate(type)
		if type == 'k' or type == 'q' or type == 'j'
			return 10
		elsif type == 'a'
			return 11
		else
			return type.to_i
		end
	end

	def print()
		puts "This card has face of #{@type} and suit #{@suit} with value #{@val}"
	end 
end

class Hand
	attr_accessor :handVal, :cards

	def initialize()
		@cards = []
		@handVal = 0
	end

	def getCard(aDeck)
		self.cards.push(aDeck.getCard())
	end

	def evaluateHand()
		handVal = 0
		for i in (0..@cards.length - 1)
			handVal += @cards[i].val
		end

		self.handVal = handVal
	end

	def print(strPerson)
		puts "#{strPerson}: #{@cards.length} cards with  a value of #{@handVal}"
	end

end	

class Deck
	attr_accessor :cardtypes, :cards

	def initialize()
		@cardtypes = { '2' => 'chds', '3' => 'chds', '4' => 'chds', '5' => 'chds', '6' => 'chds',  
			       '7' => 'chds', '8' => 'chds', '9' => 'chds', '10' => 'chds', 'j' => 'chds', 
 			       'q' => 'chds', 'k' => 'chds', 'a' => 'chds' }
		@cards = ['2','3','4','5','6','7','8','9','10','j','q','k','a']
	end

	def getCard()
		i = Random.rand(@cards.length - 1)
		card = @cards[i]

		isLoop = true
		until isLoop == false
			i = Random.rand(@cards.length)
			card = @cards[i]
		
			if @cardtypes[card] == ''
				self.cards.delete(self.cards[i])
			else
				isLoop = false
			end
		end
		
		suit = @cardtypes[card][Random.rand(@cardtypes[card].length)]

		if @cardtypes[card].length == 1
			@cardtypes[card] = ''
		elsif @cardtypes[card].length == 2
			@cardtypes[card] = @cardtypes[card][1]
		else
			@cardtypes[card] = @cardtypes[card][1..@cardtypes.length - 1]

		end
		
		return Card.new(suit, card)
	end
end

class Blackjack
	attr_accessor :deck, :player, :dealer, :dealerDone, :playerDone

	def initialize()
		@dealerDone = false
		@playerDone = false
		@deck = Deck.new()
		@player = Hand.new()
		@dealer = Hand.new()
	end

	def run()
		puts "*" * 50
		puts "Welcome to the Blackjack game! Prepare to battle the dealer for money!"
		puts "*" * 50

		continue = true
		until continue == false
			if self.playerDone != true
				self.playerTurn()
			end
			if self.dealerDone != true
				self.dealerTurn()
			end

			if self.dealerDone == true and self.playerDone == true
				self.checkVictory()
				continue = false
				puts "Goodbye!"
			end

		end
	end

	def playerTurn()

		isLoop = true
		while isLoop == true
			puts "_" * 50
			puts "Player! It's your turn!"
			print "What would you like to do?\n1. Hit me\n2. Stay\n3. Evaluate hand\n-> "
			op = gets.chomp()
			if op == '1' 
				self.player.getCard(self.deck)
				self.player.cards[-1].print()
				self.player.evaluateHand()
				self.player.print('You')
				isLoop = false
			elsif op == '2'
				isLoop = false
				self.playerDone = true
			elsif op == '3'
				self.player.evaluateHand()
				self.player.print('You')	
			end
			puts "_" * 50
			
		end
	end	
	
	def dealerTurn()
		self.dealer.evaluateHand()
		puts "-" * 50
		if self.dealer.handVal <= 17
			self.dealer.getCard(self.deck)
			self.dealer.evaluateHand()
		else
			self.dealerDone = true
		end
		puts "The dealer has #{self.dealer.cards.length} cards with a total value of #{self.dealer.handVal}"
		puts "-" * 50
	end
			
	def controlAces()
		for i in (0.. self.player.cards.length - 1)
			if self.player.cards[i].type == 'a'
				self.player.cards[i].val = 1
			end
		end
		
		for i in (0..self.dealer.cards.length - 1)
			if self.dealer.cards[i].type == 11
				self.dealer.cards[i].val = 1
			end
		end
		
		self.player.evaluateHand()
		self.player.evaluateHand()
	end

	def checkVictory()
		self.controlAces()

		if self.player.handVal == 21
			self.victory!()
		elsif self.player.handVal > 21
			self.loss!() 
		elsif self.dealer.handVal > 21
			self.victory!()
		elsif self.player.handVal >= self.dealer.handVal
			self.victory!()
		elsif self.player.handVal < self.dealer.handVal
			self.loss!()
		end
	end

	def victory!()
		puts "You won! Yay!"
	end

	def loss!()
		puts "You lost. Better luck next time?"
	end

end

agame = Blackjack.new()
agame.run()
 

#acard = Card.new('h', 'k')
#acard.suit = 's'
#adeck = Deck.new()

#ahand = Hand.new()
#for i in (0..10)
#	ahand.getCard(adeck)
#	ahand.evaluateHand()
#	ahand.print()
#end

#cardArr = []
#for i in (0..10)
#	cardArr.push(adeck.getCard())
#	cardArr[i].print()
#end

