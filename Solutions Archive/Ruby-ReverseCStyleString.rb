def validCLInput?(inArr)
	for i in (0..(inArr.length - 1))
		if inArr[i].length > 1 and inArr[i] != '\0'
			return false
		end
	end
	true
end

def reverseCString(inArr)
	strOut = ""
	for i in (inArr.length - 2).downto(0)
		strOut += inArr[i]
	end
	strOut += '\0'
end

def main()
	arrIn = *ARGV
	arrIn.push('\0')
	puts "Welcome to the Ruby version of the reverse C-Style string program!"
	if validCLInput?(arrIn) == true
		puts "The reversed C-style string of your input is: #{reverseCString(arrIn)}"
	else
		puts "Please run the program again with a sequence of single elements after the program name.\nThese must be space delimited"
	end
end

main()
