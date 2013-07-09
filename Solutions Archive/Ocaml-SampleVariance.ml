let double x = x *. x;;
let sum_of_list l = List.fold_left (+.) 0.0 l;;
let diff_of_squares x y = double(x -. y);;
let avg l = ((sum_of_list l) /. (float_of_int(List.length l)));;
let sampleVar l = (sum_of_list(List.map (diff_of_squares(avg l)) l)) /. ((float_of_int(List.length l)) -. 1.);;

print_string("The sample variance is " ^ string_of_float(sampleVar([1.;2.;3.;4.;5.])) ^ "\n");;
