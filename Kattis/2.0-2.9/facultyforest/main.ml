let n, m = Scanf.scanf "%d %d\n" (fun n m -> n, m) in
let g = Array.make n [] in
for _ = 1 to m do
  let u, v = Scanf.scanf "%d %d\n" (fun u v -> u - 1, v - 1) in
  g.(u) <- v :: g.(u);
  g.(v) <- u :: g.(v)
done;
let seen = Array.make n false in
let rec dfs u p =
  seen.(u) <- true;
  List.iter (fun v -> if v <> p then dfs v u) g.(u)
in
let ans = ref 0 in
for i = 0 to n - 1 do
  if not seen.(i)
  then (
    ans := !ans + 1;
    dfs i (-1))
done;
Printf.printf "%d\n" !ans
