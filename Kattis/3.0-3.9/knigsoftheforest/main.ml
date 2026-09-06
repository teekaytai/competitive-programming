let k, n = Scanf.scanf "%d %d\n" (fun k n -> k, n) in
let x, y = Scanf.scanf "%d %d\n" (fun x y -> x, y) in
let a = Array.init (n + k - 2) (fun _ -> Scanf.scanf "%d %d\n" (fun x y -> x, y)) in
Array.fast_sort compare a;
let exception Break in
try
  if k = 1
  then (
    Printf.printf "%d\n" x;
    raise Break);
  let _ =
    Array.fold_left
      (fun t (x2, y2) ->
         let t' = t + if y2 < y then 1 else 0 in
         if t' >= k - 1
         then (
           Printf.printf "%d\n" (Int.max x2 x);
           raise Break);
         t')
      0
      a
  in
  print_endline "unknown"
with
| Break -> ()
