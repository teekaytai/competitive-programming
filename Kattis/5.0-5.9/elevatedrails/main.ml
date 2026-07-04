let n, q = Scanf.scanf "%d %d\n" (fun n q -> n, q) in
let g = Array.make n [] in
for _ = 1 to n - 3 do
  let u, v = Scanf.scanf "%d %d\n" (fun u v -> u - 1, v - 1) in
  g.(u) <- v :: g.(u);
  g.(v) <- u :: g.(v)
done;
let diams = Array.make 3 (-1) in
let ids = Array.make n (-1) in
let ds = Array.make n (-1) in
let aux = Array.make n (-1) in
let rec dfs id ds d u p =
  ids.(u) <- id;
  ds.(u) <- d;
  List.fold_left
    (fun acc v -> if v = p then acc else max acc (dfs id ds (d + 1) v u))
    (d, u)
    g.(u)
in
let cid = ref 0 in
for s = 0 to n - 1 do
  if ids.(s) = -1
  then (
    let _, a = dfs !cid ds 0 s (-1) in
    let diam, b = dfs !cid ds 0 a (-1) in
    ignore (dfs !cid aux 0 b (-1));
    diams.(!cid) <- diam;
    cid := !cid + 1)
done;
Array.iteri (fun i d -> ds.(i) <- Int.max ds.(i) d) aux;
for _ = 1 to q do
  let u, v = Scanf.scanf "%d %d\n" (fun u v -> u - 1, v - 1) in
  Printf.printf "%d\n" (ds.(u) + diams.(3 - ids.(u) - ids.(v)) + ds.(v) + 3)
done
