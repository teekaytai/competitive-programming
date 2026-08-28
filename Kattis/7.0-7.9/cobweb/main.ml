let n, m, a, s = Scanf.scanf "%d %d\n%s\n%s\n" (fun n m a s -> n, m, a, s) in
let g = Array.init n (fun _ -> Dynarray.create ()) in
for i = 0 to n - 2 do
  let u, v = Scanf.scanf "%d %d\n" (fun u v -> u - 1, v - 1) in
  Dynarray.add_last g.(u) (v, 2 * i);
  Dynarray.add_last g.(v) (u, (2 * i) + 1)
done;
let dp1 = Array.make_matrix (m + 1) n (-1) in
let dp2 = Array.make_matrix (m + 1) (2 * (n - 1)) (-1) in
let rec dfs u p pe =
  dp1.(m).(u) <- n;
  let t = ref 1 in
  Dynarray.iter
    (fun (v, ve) ->
       if v <> p
       then (
         let x = dfs v u ve in
         dp2.(m).(ve) <- x;
         t := !t + x))
    g.(u);
  if pe >= 0 then dp2.(m).(pe lxor 1) <- n - !t;
  !t
in
ignore (dfs 0 (-1) (-1));
let rec f i u pe =
  if dp1.(i).(u) = -1
  then
    if a.[u] < s.[i]
    then (
      dp1.(i).(u) <- 0;
      Dynarray.iter (fun (_, ve) -> dp2.(i).(ve) <- 0) g.(u))
    else if a.[u] > s.[i]
    then (
      dp1.(i).(u) <- n;
      Dynarray.iter (fun (_, ve) -> dp2.(i).(ve) <- dp2.(m).(ve)) g.(u))
    else (
      let t = ref 0 in
      Dynarray.iter
        (fun (v, ve) ->
           let x = f (i + 1) v ve in
           dp2.(i).(ve) <- x;
           t := !t + x)
        g.(u);
      dp1.(i).(u) <- (!t + if i = m - 1 then 1 else 0));
  dp1.(i).(u) - if pe >= 0 then dp2.(i).(pe lxor 1) else 0
in
let ans = ref 0 in
for i = 0 to n - 1 do
  ans := !ans + f 0 i (-1)
done;
Printf.printf "%d\n" !ans
