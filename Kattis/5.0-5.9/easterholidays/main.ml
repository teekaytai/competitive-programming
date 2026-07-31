let topo g =
  let n = Array.length g in
  let indegs = Array.make n 0 in
  Array.iter (fun e -> List.iter (fun (v, _) -> indegs.(v) <- indegs.(v) + 1) e) g;
  let st =
    Array.to_seqi indegs
    |> Seq.filter_map (fun (i, d) -> if d = 0 then Some i else None)
    |> List.of_seq
  in
  let o = Array.make n (-1) in
  let rec helper st i =
    match st with
    | [] -> ()
    | u :: st2 ->
      let st2 = ref st2 in
      o.(i) <- u;
      List.iter
        (fun (v, _) ->
           indegs.(v) <- indegs.(v) - 1;
           if indegs.(v) = 0 then st2 := v :: !st2)
        g.(u);
      helper !st2 (i + 1)
  in
  helper st 0;
  o
;;

let f g o s cmp id =
  let n = Array.length g in
  let dp = Array.make n (id, -1) in
  for i = 0 to n - 1 do
    let u = o.(i) in
    if u = s then dp.(u) <- 0, -1;
    let d = fst dp.(u) in
    if d <> id
    then
      List.iter
        (fun (v, w) ->
           let d2 = d + w in
           dp.(v) <- cmp dp.(v) (d2, u))
        g.(u)
  done;
  dp
;;

let rec get_path dp s t acc =
  if s = t
  then acc
  else (
    let p = snd dp.(t) in
    get_path dp s p (p :: acc))
;;

for _ = 1 to read_int () do
  let n, m, k = Scanf.scanf "%d %d %d\n" (fun n m k -> n, m, k) in
  let g1 = Array.make n [] in
  let g2 = Array.make n [] in
  for _ = 1 to m do
    let u, v, w = Scanf.scanf "%d %d %d\n" (fun u v w -> u - 1, v - 1, w) in
    g2.(v) <- (u, w) :: g2.(v)
  done;
  for _ = 1 to k do
    let u, v, w = Scanf.scanf "%d %d %d\n" (fun u v w -> u - 1, v - 1, w) in
    g1.(u) <- (v, w) :: g1.(u)
  done;
  let o1 = topo g1 in
  let o2 = topo g2 in
  let best = ref None in
  for s = 0 to n - 1 do
    let dp1 = f g1 o1 s min Int.max_int in
    let dp2 = f g2 o2 s max Int.min_int in
    let mx = ref (0.0, -1) in
    for t = 0 to n - 1 do
      let d1 = fst dp1.(t) in
      let d2 = fst dp2.(t) in
      if d1 < Int.max_int && d1 > 0 && d2 > 0
      then mx := max !mx (float_of_int d2 /. float_of_int d1, t)
    done;
    best
    := match !best with
       | None -> Some (!mx, s, dp1, dp2)
       | Some (x, _, _, _) -> if !mx > x then Some (!mx, s, dp1, dp2) else !best
  done;
  let (x, t), s, dp1, dp2 = Option.get !best in
  let path = get_path dp1 s t (t :: List.rev (get_path dp2 s t [])) in
  List.iter (fun v -> Printf.printf "%d " (v + 1)) path;
  Printf.printf "\n%.3f\n" x
done
