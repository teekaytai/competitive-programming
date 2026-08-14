let w, h = Scanf.scanf "%d %d" (fun w h -> w, h) in
let m = Int.min w h in
let a = w * h in
let ans =
  if 314159265 * m * m >= 200000000 * a
  then "circle"
  else if m * m * 2 >= a
  then "square"
  else "blank"
in
print_endline ans
