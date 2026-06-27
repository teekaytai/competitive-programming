let n = read_int () in
let a =
  List.init n (fun _ -> Scanf.sscanf (read_line ()) "%d %d %d" (fun h l r -> h, l, r))
in
let ans =
  List.fold_left
    (fun acc (h, l, r) ->
       let mx1, mx2 =
         List.fold_left
           (fun (m1, m2) (h2, l2, r2) ->
              if h <= h2
              then m1, m2
              else
                ( (if l2 <= l && l < r2 then Int.max m1 h2 else m1)
                , if l2 < r && r <= r2 then Int.max m2 h2 else m2 ))
           (0, 0)
           a
       in
       acc + h + h - mx1 - mx2)
    0
    a
in
Printf.printf "%d\n" ans
