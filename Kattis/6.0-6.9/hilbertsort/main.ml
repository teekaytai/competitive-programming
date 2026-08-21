let rec f i s x y acc =
  if i = 31
  then acc
  else (
    let bx = x * 2 >= s in
    let by = y * 2 >= s in
    let acc' = (acc * 4) + (if bx then 2 else 0) + if by <> bx then 1 else 0 in
    let x', y' =
      if by
      then (if bx then (2 * x) - s else 2 * x), (2 * y) - s
      else if bx
      then s - (2 * y), 2 * (s - x)
      else 2 * y, 2 * x
    in
    f (i + 1) s x' y' acc')
;;

let n, s = Scanf.scanf "%d %d\n" (fun n s -> n, s) in
let a =
  Array.init n (fun _ ->
    let x, y = Scanf.scanf "%d %d\n" (fun x y -> x, y) in
    f 0 s x y 0, x, y)
in
Array.fast_sort (fun (z1, _, _) (z2, _, _) -> Int.compare z1 z2) a;
Array.iter (fun (_, x, y) -> Printf.printf "%d %d\n" x y) a
