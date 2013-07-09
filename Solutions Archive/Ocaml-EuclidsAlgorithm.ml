let rec gcd a b = 
	if a mod b = 0 then
		b
	else 
		gcd b a mod b;;

print_string("The GCD of 30 330 is " ^ string_of_int(gcd 30 330) ^ "\n");;
