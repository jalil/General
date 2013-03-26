def removeDuplicates(inStr)
	outStr = ""
	for i in (0.. inStr.length - 1)
		if outStr.count(inStr[i]) == 0
			outStr += inStr[i]
		end
	end
	outStr
end

def main()
	inStr = ARGV.first
	if inStr == nil
		puts "Please insert a string as a command line argument"
	else
		puts "The string, #{inStr}, becomes #{removeDuplicates(inStr)} when its duplicative characters are removed"
	end
end

main()			
