arg1 = ARGV.first

def factorial(n)
        if n == 0
                return 1
        else
                return n * factorial(n-1)
        end
end


if arg1.to_i != 0
	n = arg1.to_i
	puts factorial(n)
else
	puts "Please input a value as a part of your command line argument"
end

