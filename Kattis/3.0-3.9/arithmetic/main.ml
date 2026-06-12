let s = read_line () in
let last_c, _, lst =
  String.fold_right
    (fun d (c, i, acc) ->
       let d = Char.code d - Char.code '0' in
       match i with
       | 0 -> d, 3, acc
       | 1 -> 0, 0, ((d * 2) + c) :: acc
       | 2 -> d / 4, 1, ((d mod 4 * 4) + c) :: acc
       | _ -> d / 2, 2, ((d mod 2 * 8) + c) :: acc)
    s
    (0, 0, [])
in
let res = if Int.equal last_c 0 && lst <> [] then lst else last_c :: lst in
List.iter
  (fun c -> if c >= 10 then print_char (Char.chr (65 + c - 10)) else print_int c)
  res;
print_newline ()
