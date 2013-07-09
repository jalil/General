let double x = x *. x;;
let sum_of_list l = List.fold_left (+.) 0.0 l;;
let diff_of_squares x y = double(x -. y);;
let avg l = ((sum_of_list l) /. (float_of_int(List.length l)));;
let popVar l = sum_of_list(List.map (diff_of_squares(avg l)) l) /. float_of_int(List.length l);;

print_string("The pop variance is " ^ string_of_float(popVar([1.;2.;3.;4.;5.])) ^ "\n");;
