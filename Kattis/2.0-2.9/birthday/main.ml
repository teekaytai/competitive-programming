let rec dfs g seen tin low timer u p =
  seen.(u) <- true;
  tin.(u) <- !timer;
  low.(u) <- !timer;
  timer := !timer + 1;
  List.exists
    (fun v ->
       if v = p
       then false
       else if seen.(v)
       then (
         low.(u) <- Int.min low.(u) tin.(v);
         false)
       else if dfs g seen tin low timer v u
       then true
       else (
         low.(u) <- Int.min low.(u) low.(v);
         low.(v) > tin.(u)))
    g.(u)
;;

let n, m = Scanf.scanf "%d %d\n" (fun n m -> ref n, ref m) in
while !n <> 0 do
  let g = Array.make !n [] in
  for _ = 1 to !m do
    let u, v = Scanf.scanf "%d %d\n" (fun u v -> u, v) in
    g.(u) <- v :: g.(u);
    g.(v) <- u :: g.(v)
  done;
  let seen = Array.make !n false in
  let tin = Array.make !n (-1) in
  let low = Array.make !n (-1) in
  let has_bridge = dfs g seen tin low (ref 0) 0 (-1) in
  let ans = if has_bridge || Array.exists not seen then "Yes" else "No" in
  print_endline ans;
  let n2, m2 = Scanf.scanf "%d %d\n" (fun n m -> n, m) in
  n := n2;
  m := m2
done
