let median lst = 
	if List.length lst  mod 2 != 0 then
		List.nth lst ((List.length lst) / 2)
	else
		((List.nth lst (((List.length lst) / 2) - 1)) +. (List.nth lst ((List.length lst) / 2))) /. 2.;;

let l1 = [1.;2.;3.;4.];;
let l2 = [1.;2.;3.;4.;5.];;

print_string("The median of the list [1,2,3,4] is " ^ string_of_float(median l1) ^ " and the median of the list [1,2,3,4,5] is " ^ string_of_float(median l2) ^ "\n")
