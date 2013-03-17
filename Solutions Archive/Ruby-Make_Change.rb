change = ARGV.first

def makeChange(intChange)
	hashChange = {  "Quarters" => 0,
		        "Dimes" => 0,
			"Nickels" => 0,
	       		"Pennies" => 0 }

	while intChange > 0
		if intChange - 25 >= 0
			hashChange["Quarters"] += 1
			intChange -= 25
		elsif intChange - 10 >= 0
			hashChange["Dimes"] += 1
			intChange -= 10
		elsif intChange - 5 >= 0
			hashChange["Nickels"] += 1
			intChange -= 5
		elsif intChange - 1 >= 0
			hashChange["Pennies"] += 1
			intChange -= 1
		end
	end
	return hashChange
end

hashChange = makeChange(change.to_i)

puts "The intitial change amount, #{25 * hashChange["Quarters"] + 10 * hashChange["Dimes"] + 5 * hashChange["Nickels"] + hashChange["Pennies"]}, can be subdivided into the follows: "
puts "Quarters: #{hashChange["Quarters"]}"
puts "Dimes: #{hashChange["Dimes"]}"
puts "Nickels: #{hashChange["Nickels"]}"
puts "Pennies: #{hashChange["Pennies"]}"

puts "Goodbye!"



