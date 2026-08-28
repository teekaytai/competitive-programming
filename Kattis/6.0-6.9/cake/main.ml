let h, w, n = Scanf.scanf "%d %d %d\n" (fun h w n -> h, w, n) in
let a =
  Array.init (n + 1) (fun i ->
    if i = n then h + 1, 0 else Scanf.scanf "%d %d\n" (fun r c -> r, c))
in
Array.fast_sort compare a;
let lo = ref 0 in
let r = ref (fst a.(0)) in
for hi = 0 to n do
  let r2 = fst a.(hi) in
  if r2 <> !r
  then (
    let r' = if !lo = 0 then 1 else !r in
    for i = !lo to hi - 1 do
      let c1 = if i = !lo then 1 else snd a.(i - 1) + 1 in
      let c2 = if i = hi - 1 then w else snd a.(i) in
      Printf.printf "%d %d %d %d\n" r' c1 (r2 - 1) c2
    done;
    r := r2;
    lo := hi)
done;
print_endline "0"
