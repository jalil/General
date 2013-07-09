let rec pow a b =
	if b = 0 then
		1.0
	else
		a *. (pow a (b - 1));;

print_string("The value of 2 raised to the fifth power is " ^ string_of_float(pow 2. 5) ^ "\n");;

