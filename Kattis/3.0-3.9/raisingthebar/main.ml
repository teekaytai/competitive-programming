let n, d = Scanf.scanf "%d %d\n" (fun n d -> n, d) in
let rec f h n d =
  let i = Hashtbl.length h in
  match Hashtbl.find_opt h n with
  | Some j -> j, i - j
  | None ->
    let r = 10 * n mod d in
    if r = 0
    then 1 + i, 0
    else (
      Hashtbl.add h n i;
      f h r d)
in
let a, b = f (Hashtbl.create d) n d in
Printf.printf "%d %d\n" a b
