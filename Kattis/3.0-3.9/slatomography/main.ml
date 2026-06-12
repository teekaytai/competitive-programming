let a = Array.init (read_int ()) (fun _ -> read_int ()) in
let _, ans =
  Array.fold_right
    (fun x (p, t) ->
       if x > p
       then x, t + x - p + Bool.to_int (p = 0)
       else if x < p
       then x, t + Bool.to_int (x > 0)
       else x, t)
    a
    (0, 1)
in
Printf.printf "%d\n" ans
