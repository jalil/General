def iterReplace(strIn)
	strOut = ""
	for i in (0..strIn.length - 1)
		if i + 2 < strIn.length and i + 1 > strOut.length
			if strIn[i.. i + 2] == 'foo'
				strOut += 'bar'
			else
				strOut += strIn[i]
			end
		elsif i + 1 > strOut.length
			strOut += strIn[i]
		end
	end
	strOut
end

def main()
	inStr = ARGV.first
	if inStr == nil
		puts "You need to supply a command line argument to this program indicating the string\n in which you would like to replace the \"foo\"s with \"bar\"s"
	else
		puts "Your initial string #{inStr} becomes #{iterReplace(inStr)} after replacement of all\n 'foo' occurrences with 'bar' occurrences"
	end
end

main()

