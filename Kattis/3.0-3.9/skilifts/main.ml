let n = Scanf.scanf "%d\n" (fun n -> n) in
let a = Array.init n (fun _ -> Scanf.scanf "%d %d %d\n" (fun _ y t -> y, -t)) in
Array.fast_sort compare a;
let ans, _, _, _ =
  Array.fold_left
    (fun (acc, py, ps, s) (y, t) ->
       let py2, ps2, s2 =
         if Int.equal y (py + 1)
         then py, ps, s
         else if Int.equal y (py + 2)
         then y - 1, s, 0
         else y - 1, 0, 0
       in
       let v = Bool.to_int (ps2 > 0) in
       let d = Int.min (-t - v) 1 in
       acc + v, py2, ps2 - v, s2 + d)
    (0, -2, 0, 0)
    a
in
Printf.printf "%d\n" ans
