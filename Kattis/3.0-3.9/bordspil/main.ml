let n, m = Scanf.scanf "%d %d" (fun n m -> n, m) in
let m2 = m - 1 in
let a = m2 / 2 in
let b = m2 - a in
print_endline (if n >= a + b + b then "Arnar" else "Unnar")
