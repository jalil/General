let last lst = List.nth lst ((List.length lst) - 1);;

print_string("The last element of the list [1,2,3,4,5] is " ^ string_of_int(last [1;2;3;4;5]) ^ "\n");;
