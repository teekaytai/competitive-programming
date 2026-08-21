let n, k, d = Scanf.sscanf (read_line ()) "%d %d %d" (fun n k d -> n, k, d) in
let a =
  read_line ()
  |> String.split_on_char ' '
  |> List.fold_left (fun acc x -> acc + (1 lsl int_of_string x)) 0
in
let x = d - (a lsr 1) in
Printf.printf
  "%d\n"
  (if x >= 0 && x land ((1 lsl (n + 1)) - 2 - a) = x then 1 lsl k else 0)
