let sum_of_list l = List.fold_left (+.) 0.0 l;;

print_string("The sum of the list [1,2,3,4,5] is " ^ string_of_float(sum_of_list [1.;2.;3.;4.;5.]) ^ "\n");;
