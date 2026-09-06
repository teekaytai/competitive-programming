module Node = struct
  type t =
    { id : int
    ; path : int list
    ; cs : t Dynarray.t
    }

  let counter = ref 1
  let root = { id = 0; path = [ 0 ]; cs = Dynarray.create () }
  let equal t1 t2 = Int.equal t1.id t2.id
  let hash t = t.id

  let n_children { path; cs; _ } n =
    while Dynarray.length cs < n do
      let l = Dynarray.length cs + 1 in
      let t' = { id = !counter; path = l :: path; cs = Dynarray.create () } in
      counter := !counter + 1;
      Dynarray.add_last cs t'
    done;
    Dynarray.to_seq cs |> Seq.take n
  ;;

  let print t =
    List.iter (fun x -> Printf.printf "%d " x) t.path;
    print_newline ()
  ;;
end

module NodeHashtbl = Hashtbl.Make (Node)

let read_char () = Scanf.scanf "%c" Fun.id;;

ignore (read_char ());
let rec f () =
  let h = NodeHashtbl.create 0 in
  let rec loop () =
    if read_char () = '('
    then (
      let ps = f () in
      Seq.iter
        (fun p ->
           match NodeHashtbl.find_opt h p with
           | None -> NodeHashtbl.add h p 1
           | Some v -> NodeHashtbl.replace h p (v + 1))
        ps;
      loop ())
  in
  loop ();
  NodeHashtbl.to_seq h
  |> Seq.flat_map (fun (node, v) -> Node.n_children node v)
  |> Seq.cons Node.root
in
let res = f () |> Seq.map (fun (node : Node.t) -> node.path, node) |> Dynarray.of_seq in
let rec g a =
  if Dynarray.length a < 2
  then Dynarray.iter (fun (_, node) -> Node.print node) a
  else (
    let b = Dynarray.create () in
    Dynarray.iter
      (fun (path, node) ->
         match path with
         | [] -> Node.print node
         | x :: xs ->
           while Dynarray.length b <= x do
             Dynarray.add_last b (Dynarray.create ())
           done;
           Dynarray.add_last (Dynarray.get b x) (xs, node))
      a;
    Dynarray.iter g b)
in
g res
