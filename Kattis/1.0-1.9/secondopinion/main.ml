let s = read_int () in
let m = s / 60 in
let h = m / 60 in
Printf.printf "%d : %d : %d\n" h (m mod 60) (s mod 60)
