let n, k = Scanf.scanf "%d %d\n" (fun n k -> n, k) in
let xor_sum = ref 0 in
for _ = 1 to n do
  let m = Scanf.scanf "%d " Fun.id in
  let a = Array.init m (fun _ -> Scanf.scanf "%d " Fun.id) in
  let dp = Array.make (m + 1) 0 in
  let cs = Array.make (k + 2) 0 in
  for i = 1 to m do
    let x = a.(i - 1) in
    if x <= i
    then (
      let v = dp.(i - x) in
      cs.(v) <- cs.(v) + 1);
    let mex = Array.find_index (( = ) 0) cs |> Option.get in
    dp.(i) <- mex;
    if i > k
    then (
      let j = i - k in
      let y = a.(j - 1) in
      if y <= j
      then (
        let v = dp.(j - y) in
        cs.(v) <- cs.(v) - 1))
  done;
  xor_sum := !xor_sum lxor dp.(m)
done;
print_endline (if !xor_sum = 0 then "Bob will win." else "Alice can win.")
