let n = Scanf.scanf "%d\n" Fun.id in
let a = Array.init n (fun _ -> Scanf.scanf "%d " Fun.id) in
let ans =
  let l = ref 0 in
  while !l < n - 1 && a.(!l) <= a.(!l + 1) do
    l := !l + 1
  done;
  if !l = n - 1
  then Some (1, 1)
  else (
    let r = ref (!l + 1) in
    while !l > 0 && a.(!l) = a.(!l - 1) do
      l := !l - 1
    done;
    while !r < n - 1 && a.(!r) >= a.(!r + 1) do
      r := !r + 1
    done;
    let left_can = !l = 0 || a.(!l - 1) <= a.(!r) in
    let right_can = !r = n - 1 || a.(!l) <= a.(!r + 1) in
    let remaining_sorted =
      !r = n - 1
      || Seq.ints (!r + 1)
         |> Seq.take (n - !r - 2)
         |> Seq.for_all (fun i -> a.(i) <= a.(i + 1))
    in
    if left_can && right_can && remaining_sorted then Some (!l + 1, !r + 1) else None)
in
match ans with
| None -> print_endline "impossible"
| Some (l, r) -> Printf.printf "%d %d\n" l r
