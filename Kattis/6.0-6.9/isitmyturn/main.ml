let n, x = Scanf.scanf "%d %d" (fun n x -> n, x) in
let yes = ref 0 in
let no = ref 0 in
let rec f n x i =
  if x = 0
  then if i = 0 then yes := !yes + 1 else no := !no + 1
  else if i <> 0
  then
    for j = 1 to Int.min (n - 1) x do
      f n (x - j) ((i + j + 1) mod n)
    done
in
f n x 1;
print_endline (if !no = 0 then "yes" else if !yes = 0 then "no" else "maybe")
