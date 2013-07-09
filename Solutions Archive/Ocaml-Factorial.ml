let decr x = x - 1;;
let rec fact x =
	if x = 0 then
		1
	else
		x * (fact(decr x));;

print_string("The factorial of 5 is " ^ string_of_int(fact 5) ^ "\n");;
