type tree =
  | Leaf of string
  | Parent of string * node * node

and node_kind =
  | Real of tree
  | Reference

and node =
  { id : int
  ; kind : node_kind
  }

module TreeHash = struct
  type t = tree

  let equal x y =
    match x, y with
    | Leaf sx, Leaf sy -> String.equal sx sy
    | Parent (sx, nxl, nxr), Parent (sy, nyl, nyr) ->
      String.equal sx sy && Int.equal nxl.id nyl.id && Int.equal nxr.id nyr.id
    | _ -> false
  ;;

  let hash = function
    | Leaf s -> Hashtbl.hash s
    | Parent (s, nl, nr) -> Hashtbl.hash (s, nl.id, nr.id)
  ;;
end

module TreeHashtbl = Hashtbl.Make (TreeHash)

let g s n i =
  let lo = !i in
  while !i < n && 'a' <= s.[!i] && s.[!i] <= 'z' do
    i := !i + 1
  done;
  String.sub s lo (!i - lo)
;;

let rec f h s n i id =
  let w = g s n i in
  let curr_id = !id in
  id := !id + 1;
  let tree =
    if !i = n || s.[!i] <> '('
    then Leaf w
    else (
      i := !i + 1;
      let nl = f h s n i id in
      i := !i + 1;
      let nr = f h s n i id in
      i := !i + 1;
      Parent (w, nl, nr))
  in
  match TreeHashtbl.find_opt h tree with
  | None ->
    TreeHashtbl.add h tree curr_id;
    { id = curr_id; kind = Real tree }
  | Some v ->
    id := !id - 1;
    { id = v; kind = Reference }
;;

let rec p = function
  | { id; kind = Reference } -> print_int id
  | { id = _; kind = Real (Leaf s) } -> print_string s
  | { id = _; kind = Real (Parent (s, nl, nr)) } ->
    print_string s;
    print_char '(';
    p nl;
    print_char ',';
    p nr;
    print_char ')'
;;

for _ = 1 to read_int () do
  let s = read_line () in
  let res = f (TreeHashtbl.create 50000) s (String.length s) (ref 0) (ref 1) in
  p res;
  print_newline ()
done
