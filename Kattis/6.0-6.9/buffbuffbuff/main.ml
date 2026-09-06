module P = struct
  type t = int * int

  let compare = compare
end

module PSet = Set.Make (P)

let read_int () = Scanf.scanf " %d" Fun.id;;

let h = Hashtbl.create 200000 in
let s = ref PSet.empty in
let o = ref 0 in
for _ = 1 to read_int () do
  match Scanf.scanf " %s" Fun.id with
  | "ADD" ->
    let k = read_int () in
    let x = read_int () - !o in
    (match Hashtbl.find_opt h k with
     | None ->
       Hashtbl.add h k x;
       s := PSet.add (x, k) !s
     | Some c ->
       if x > c
       then (
         Hashtbl.replace h k x;
         s := !s |> PSet.remove (c, k) |> PSet.add (x, k)))
  | "BUFF_ALL" ->
    let b = read_int () in
    o := !o + b
  | "BUFF" ->
    let k = read_int () in
    let b = read_int () in
    (match Hashtbl.find_opt h k with
     | None -> ()
     | Some c ->
       Hashtbl.replace h k (c + b);
       s := !s |> PSet.remove (c, k) |> PSet.add (c + b, k))
  | "MAX" -> Printf.printf "%d\n" (fst (PSet.max_elt !s) + !o)
  | _ -> assert false
done
