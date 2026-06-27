let n, c, b = Scanf.scanf "%d %d %d\n" (fun n c b -> n, c, b) in
let a = Array.make 2022 0 in
for _ = 1 to n do
  let l, r = Scanf.scanf "%d %d\n" (fun l r -> if l <= r then l, r else r, l) in
  a.(l) <- a.(l) - 1;
  a.(r + b + 1) <- a.(r + b + 1) + 1
done;
let ans, _ =
  Array.fold_left
    (fun (can, t) d ->
       let t2 = t + d in
       can && t2 >= 0, t2)
    (true, c)
    a
in
print_endline (if ans then "possible" else "impossible")
