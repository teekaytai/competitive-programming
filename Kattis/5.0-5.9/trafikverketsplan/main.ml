module IntSet = Set.Make (Int);;

let n = Scanf.scanf "%d\n" (fun n -> n) in
let g = Array.make n [] in
for _ = 1 to n - 1 do
  let u, v = Scanf.scanf "%d %d\n" (fun u v -> u - 1, v - 1) in
  g.(u) <- v :: g.(u)
done;
let dp = Array.make n None in
let rec f u =
  match dp.(u) with
  | Some res -> res
  | None ->
    let sz, s, mx_v =
      List.fold_left
        (fun acc v ->
           let sz, s = f v in
           max acc (sz, s, v))
        (0, IntSet.empty, -1)
        g.(u)
    in
    let res =
      List.fold_left
        (fun (sz, s) v ->
           if v = mx_v
           then sz, s
           else (
             let sz2, s2 = f v in
             sz + sz2, IntSet.add_seq (IntSet.to_seq s2) s))
        (sz + 1, IntSet.add u s)
        g.(u)
    in
    dp.(u) <- Some res;
    res
in
let q = Scanf.scanf "%d\n" (fun q -> q) in
for _ = 1 to q do
  let u, v = Scanf.scanf "%d %d\n" (fun u v -> u - 1, v - 1) in
  print_endline (if IntSet.mem v (snd (f u)) then "ja" else "nej")
done
