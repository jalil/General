let l = [1.;2.;3.;4.;5.];;
let avg lst = (List.fold_left (+.) 0.0 lst) /. float_of_int(List.length lst);;

print_string("The average of 1,2,3,4,5 is " ^ string_of_float(avg l) ^ "\n");;
