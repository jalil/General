let rec bin_coef n k i =
	if i = k then
		((n -. (k -. i)) /. i)
	else
		((n -. (k -. i)) /. i) *. bin_coef n k (i +. 1.);;

print_string("The binomial coefficient of 5 choose 3 is " ^ string_of_float(bin_coef 5. 3. 1.) ^ "\n");;
	
