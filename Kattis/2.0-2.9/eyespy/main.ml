let dirs = [| 1, 0; 0, 1; -1, 0; 0, -1 |]

let grid_find grid b =
  Array.to_seqi grid
  |> Seq.find_map (fun (r, row) -> Bytes.index_opt row b |> Option.map (fun c -> r, c))
;;

let in_bounds n m r c = r >= 0 && r < n && c >= 0 && c < m
let is_blocked grid r c = Char.equal (Bytes.get grid.(r) c) '#'
let is_end grid r c = Char.equal (Bytes.get grid.(r) c) 'P';;

let n, m = Scanf.sscanf (read_line ()) "%d %d" (fun n m -> n, m) in
let grid = Array.init n (fun _ -> String.to_bytes (read_line ())) in
let src = Option.get (grid_find grid 'A') in
let ps = Array.make_matrix n m (-1) in
ps.(fst src).(snd src) <- -2;
let q = Queue.create () in
Queue.add src q;
let dst = ref None in
while (not (Queue.is_empty q)) && Option.is_none !dst do
  let r, c = Queue.take q in
  for di = 0 to 3 do
    let dr, dc = dirs.(di) in
    let r2 = r + dr in
    let c2 = c + dc in
    if in_bounds n m r2 c2 && (not (is_blocked grid r2 c2)) && Int.equal ps.(r2).(c2) (-1)
    then (
      ps.(r2).(c2) <- di;
      Queue.add (r2, c2) q;
      if is_end grid r2 c2 then dst := Some (r2, c2))
  done
done;
match !dst with
| None -> print_endline "call for help"
| Some (tr, tc) ->
  let r = ref tr in
  let c = ref tc in
  while (!r, !c) <> src do
    let di = ps.(!r).(!c) in
    let dr, dc = dirs.(di) in
    r := !r - dr;
    c := !c - dc;
    if (!r, !c) <> src then Bytes.set grid.(!r) !c 'X'
  done;
  Array.iter
    (fun row ->
       print_bytes row;
       print_newline ())
    grid
