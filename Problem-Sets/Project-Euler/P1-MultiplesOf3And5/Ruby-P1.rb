def mults3or5(u)
	s = 0
	for i in (0..u - 1)
		if i % 5 == 0 or i % 3 == 0
			s += i
		end
	end
	s
end

def main()
	print "What  is the upper bound of the summation of multiples of 3 or 5?\n  -->  "
	i = gets.chomp().to_i
	puts "The summation from 0 to #{i} where the index is a multiple of 3 or 5 is #{mults3or5(i)}"
end	

main()
