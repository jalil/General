let abs x = if x >= 0 then x else -x;;

let rec gcd a b = 
	if a mod b = 0 then
		b
	else 
		gcd b a mod b;;

let lcm a b = abs a * b / gcd a b;;

print_string("The LCM of 30 330 is " ^ string_of_int(lcm 30 330) ^ "\n");;
