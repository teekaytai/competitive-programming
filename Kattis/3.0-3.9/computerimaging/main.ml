let rec f a t lo hi =
  if lo = hi
  then lo
  else (
    let mid = (lo + hi) / 2 in
    let s = List.fold_left (fun acc x -> acc + (mid / x)) 0 a in
    if s >= t then f a t lo mid else f a t (mid + 1) hi)
;;

let t = read_int () in
let n = read_int () in
let a = List.init n (fun _ -> read_int ()) in
Printf.printf "%d\n" (f a t 0 1000000)
