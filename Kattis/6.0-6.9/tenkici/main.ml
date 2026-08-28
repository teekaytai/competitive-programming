let rec cons_n n x lst = if n = 0 then lst else cons_n (n - 1) x (x :: lst);;

let n = Scanf.scanf "%d\n" Fun.id in
let a = Array.init n (fun _ -> Scanf.scanf "%d %d\n" (fun r c -> r - 1, c - 1)) in
let o = Array.init n Fun.id in
Array.fast_sort (fun i1 i2 -> Int.compare (fst a.(i1)) (fst a.(i2))) o;
let rec f i acc1 acc2 =
  if i = n
  then List.rev_append acc2 acc1
  else (
    let r = fst a.(o.(i)) in
    if i < r
    then (
      let acc1' = cons_n (r - i) (o.(i), 'U') (List.rev_append acc2 acc1) in
      f (i + 1) acc1' [])
    else f (i + 1) acc1 (cons_n (i - r) (o.(i), 'D') acc2))
in
let res = f 0 [] [] in
Array.fast_sort (fun i1 i2 -> Int.compare (snd a.(i1)) (snd a.(i2))) o;
let rec g i acc =
  if i = n
  then acc
  else (
    let c = snd a.(o.(i)) in
    let x = o.(i), if i < c then 'L' else 'R' in
    g (i + 1) (cons_n (Int.abs (i - c)) x acc))
in
let ans = g 0 res in
Printf.printf "%d\n" (List.length ans);
List.iter (fun (i, d) -> Printf.printf "%d %c\n" (i + 1) d) (List.rev ans)
