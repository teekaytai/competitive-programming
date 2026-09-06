type t =
  { d : int
  ; q : int
  ; r : int
  }
;;

let n, k = Scanf.scanf "%d %d\n" (fun n k -> n, k) in
let a =
  Array.init n (fun _ ->
    let t, d = Scanf.scanf "%d %d\n" (fun t d -> t, d) in
    let q = t / d in
    let r = t mod d in
    { d; q; r })
in
let rec loop lo hi =
  if lo = hi
  then lo
  else (
    let mid = (lo + hi) / 2 in
    let v1, v2 =
      Array.fold_left
        (fun (acc1, acc2) { d; q; r } ->
           let x =
             (d * Int.max (q - mid - 1) 0)
             + if q > mid then r + 1 else if q = mid && r > 0 then 1 else 0
           in
           let y = Int.min (q + if r > 0 then 1 else 0) mid in
           acc1 + x, acc2 + y)
        (0, 0)
        a
    in
    if v1 <= k && (v1 + v2 + k - 1) / k <= mid + 1 then loop lo mid else loop (mid + 1) hi)
in
let ans = loop 0 (int_of_float 3e14) in
Printf.printf "%d\n" ans
