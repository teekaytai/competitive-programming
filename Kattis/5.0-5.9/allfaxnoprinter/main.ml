module P = struct
  type t = int * int

  let compare = compare
end

module PSet = Set.Make (P)

let rec remove_le x s c =
  if not (PSet.is_empty !s)
  then (
    let mn = PSet.min_elt !s in
    if fst mn <= x
    then (
      s := PSet.remove mn !s;
      c := !c - 1;
      remove_le x s c))
;;

let n, k = Scanf.scanf "%d %d\n" (fun n k -> n, k) in
let t1 = ref 0 in
let t2 = ref 0 in
let s1 = ref PSet.empty in
let s2 = ref PSet.empty in
let c1 = ref 0 in
let c2 = ref 0 in
for i = 0 to n - 1 do
  let x, l = Scanf.scanf "%d %d\n" (fun x l -> x, l) in
  remove_le x s1 c1;
  remove_le x s2 c2;
  let y = x + l in
  if !c1 < k
  then (
    t1 := !t1 + 1;
    s1 := PSet.add (y, i) !s1;
    c1 := !c1 + 1);
  if !c2 < k
  then (
    t2 := !t2 + 1;
    s2 := PSet.add (y, i) !s2;
    c2 := !c2 + 1)
  else if fst (PSet.max_elt !s2) > y
  then (
    s2 := PSet.remove (PSet.max_elt !s2) !s2;
    s2 := PSet.add (y, i) !s2);
  Printf.printf "%d\n" (!t2 - !t1)
done
