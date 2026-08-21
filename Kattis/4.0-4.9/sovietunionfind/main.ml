let n, q = Scanf.scanf "%d %d\n" (fun n q -> n, q) in
let a = Array.init n Fun.id in
let ra = Array.init (n + q) Fun.id in
let bs = Array.make (n + q) true in
let ps = Array.make (n + q) (-1) in
let i = ref n in
let rec f x =
  let p = ps.(x) in
  if p = -1
  then x
  else (
    let r = f p in
    ps.(x) <- r;
    r)
in
let g x =
  let r = f a.(x) in
  if bs.(r)
  then r
  else (
    a.(x) <- !i;
    ra.(!i) <- x;
    i := !i + 1;
    a.(x))
in
for _ = 1 to q do
  let t = Scanf.scanf "%c " Fun.id in
  if t = 'a'
  then (
    let x, y = Scanf.scanf "%d %d\n" (fun x y -> x - 1, y - 1) in
    let rx = g x in
    let ry = g y in
    if rx <> ry then ps.(ry) <- rx)
  else if t = 'b'
  then (
    let x = Scanf.scanf "%d\n" (fun x -> x - 1) in
    bs.(g x) <- false)
  else (
    let x = Scanf.scanf "%d\n" (fun x -> x - 1) in
    Printf.printf "%d\n" (ra.(g x) + 1))
done
