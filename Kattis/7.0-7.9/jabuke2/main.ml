type kdtree =
  | Empty
  | Point
  | Internal of
      { l : kdtree
      ; h : kdtree
      }

type region =
  { rl : int
  ; rh : int
  ; cl : int
  ; ch : int
  }

let is_point { rl; rh; cl; ch } = rl = rh && cl = ch

let dist_to_region re r c =
  let dr = Int.max r re.rl - Int.min r re.rh in
  let dc = Int.max c re.cl - Int.min c re.ch in
  (dr * dr) + (dc * dc)
;;

let get_sorted_sub_regions re r c =
  let { rl; rh; cl; ch } = re in
  let dr = rh - rl in
  let dc = ch - cl in
  if dr >= dc
  then (
    let rm = (rl + rh) / 2 in
    let sub1 = { rl; rh = rm; cl; ch } in
    let sub2 = { rl = rm + 1; rh; cl; ch } in
    if r <= rm then true, sub1, sub2 else false, sub2, sub1)
  else (
    let cm = (cl + ch) / 2 in
    let sub1 = { rl; rh; cl; ch = cm } in
    let sub2 = { rl; rh; cl = cm + 1; ch } in
    if c <= cm then true, sub1, sub2 else false, sub2, sub1)
;;

let inf = 10000000 in
let n, m = Scanf.scanf "%d %d\n" (fun n m -> n, m) in
let tree = ref Empty in
let add r c =
  let rec loop node re =
    match node with
    | Point -> node
    | Empty ->
      if is_point re
      then Point
      else (
        let b, re', _ = get_sorted_sub_regions re r c in
        let res = loop Empty re' in
        if b then Internal { l = res; h = Empty } else Internal { l = Empty; h = res })
    | Internal { l; h } ->
      let b, re', _ = get_sorted_sub_regions re r c in
      if b then Internal { l = loop l re'; h } else Internal { l; h = loop h re' }
  in
  tree := loop !tree { rl = 1; rh = n; cl = 1; ch = m }
in
let nn r c =
  let res = ref inf in
  let rec loop node re =
    match node with
    | Empty -> ()
    | Point -> res := Int.min !res (dist_to_region re r c)
    | Internal { l; h } ->
      let b, re1, re2 = get_sorted_sub_regions re r c in
      loop (if b then l else h) re1;
      if dist_to_region re2 r c < !res then loop (if b then h else l) re2
  in
  loop !tree { rl = 1; rh = n; cl = 1; ch = m };
  !res
in
for r = 1 to n do
  let row = Scanf.scanf "%s\n" Fun.id in
  String.iteri (fun c x -> if x = 'x' then add r (c + 1)) row
done;
let q = Scanf.scanf "%d\n" Fun.id in
for _ = 1 to q do
  let r, c = Scanf.scanf "%d %d\n" (fun r c -> r, c) in
  Printf.printf "%d\n" (nn r c);
  add r c
done
