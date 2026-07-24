module P = struct
  type t = int * int

  let compare = compare
end

module PSet = Set.Make (P);;

let n, h, w = Scanf.scanf "%d %d %d\n" (fun n h w -> n, h, w) in
let p =
  List.init n (fun _ -> Scanf.scanf "%d %d %d\n" (fun r _ s -> r - s, r + s))
  |> List.sort compare
  |> ref
in
let j = ref 0 in
let pq = ref PSet.empty in
let ans = ref 0 in
for i = 1 to h do
  while !p <> [] && fst (List.hd !p) <= i do
    pq := PSet.add (snd (List.hd !p), !j) !pq;
    p := List.tl !p;
    j := !j + 1
  done;
  let c = ref w in
  while !c > 0 && not (PSet.is_empty !pq) do
    let x, k = PSet.min_elt !pq in
    pq := PSet.remove (x, k) !pq;
    if x >= i
    then (
      c := !c - 1;
      ans := !ans + 1)
  done
done;
Printf.printf "%d\n" !ans
