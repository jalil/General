def uniqueChars?(strIn)
	strOut = ""
	for i in (0..strIn.length - 1)
		if strOut.count(strIn[i]) == 0
			strOut += strIn[i]
		else
			false
		end
	end
	true
end







inStr = ARGV[0]

if inStr == nil 
	puts "Please insert a string to be evaluated"
else
	puts "The string #{inStr} has a uniqueness value of #{uniqueChars?(inStr)}"
end

