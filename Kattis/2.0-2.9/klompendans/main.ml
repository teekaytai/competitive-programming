module TileSet = Set.Make (struct
    type t = int * int

    let compare = compare
  end)

module StateSet = Set.Make (struct
    type t = int * int * bool

    let compare = compare
  end)

let () =
  let n, a, b, c, d = Scanf.scanf "%d\n%d %d\n%d %d" (fun n a b c d -> n, a, b, c, d) in
  let make_moves p q = [ p, q; p, -q; -p, q; -p, -q; q, p; q, -p; -q, p; -q, -p ] in
  let moves1 = make_moves a b in
  let moves2 = make_moves c d in
  let rec bfs seen queue =
    match queue with
    | [] -> seen
    | queue ->
      let new_seen, new_queue =
        List.fold_left
          (fun (seen, queue) (x, y, t) ->
             let moves = if t then moves1 else moves2 in
             let t2 = not t in
             List.fold_left
               (fun (seen, queue) (dx, dy) ->
                  let x2 = x + dx in
                  let y2 = y + dy in
                  let state = x2, y2, t2 in
                  if x2 < 0 || x2 >= n || y2 < 0 || y2 >= n || StateSet.mem state seen
                  then seen, queue
                  else StateSet.add state seen, state :: queue)
               (seen, queue)
               moves)
          (seen, [])
          queue
      in
      bfs new_seen new_queue
  in
  let queue = [ 0, 0, true; 0, 0, false ] in
  let states_seen = bfs (StateSet.of_list queue) queue in
  let tiles_seen =
    states_seen |> StateSet.to_seq |> Seq.map (fun (x, y, _) -> x, y) |> TileSet.of_seq
  in
  Printf.printf "%d\n" (TileSet.cardinal tiles_seen)
;;
