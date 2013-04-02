def anagrams?(strIn1, strIn2)
	if strIn1.length != strIn2.length
		return false
	else
		for i in (0..strIn1.length - 1)
			if strIn1[i] != strIn2[strIn1.length - i - 1] 
				return false
			end
		end
	end
	true
end

def main()
	arrIns = *ARGV
	if arrIns == nil or arrIns.length != 2
		puts "You have to input two strings into the command line argument for this program."
	else
		puts "It is #{anagrams?(arrIns[0], arrIns[1])} that the string, #{arrIns[0]}, and the string, #{arrIns[1]}. are anagrams."
	end
end

main()
