let n = Scanf.scanf "%d\n" Fun.id in
let a = Array.init n (fun _ -> Scanf.scanf "%d %d\n" (fun x y -> x, y)) in
let mn =
  Array.fold_left
    (fun acc (x1, y1) ->
       let t =
         Array.fold_left
           (fun s (x2, y2) ->
              let dx = x1 - x2 in
              let dy = y1 - y2 in
              s +. Float.sqrt (float_of_int ((dx * dx) + (dy * dy))))
           0.0
           a
       in
       Float.min acc t)
    Float.infinity
    a
in
Printf.printf "%.12f\n" (mn /. float_of_int (n - 1))
