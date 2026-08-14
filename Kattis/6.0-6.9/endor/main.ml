let n, k, l = Scanf.scanf "%d %d %d\n" (fun n k l -> n, k, l) in
let ans = Array.make k 0 in
let dp = Array.make k 0 in
let o = ref 0 in
let p = ref (-1) in
let first = ref (-1) in
for _ = 1 to n do
  let d, b, c = Scanf.scanf "%d %d %c\n" (fun d b c -> d, b, c) in
  if c = 'D'
  then (
    ans.(b) <- ans.(b) + (2 * (l - d));
    if !p = -1
    then first := d
    else (
      let i = (k - !o) mod k in
      dp.(i) <- dp.(i) + d - !p);
    o := (!o + b) mod k;
    p := d)
  else if !p = -1
  then ans.(b) <- ans.(b) + d + d
  else (
    ans.(b) <- ans.(b) + d - !p;
    Array.iteri
      (fun i x ->
         let j = (b + i + !o) mod k in
         ans.(j) <- ans.(j) + x)
      dp;
    let i = (b + !o) mod k in
    ans.(i) <- ans.(i) + d + !first)
done;
Array.iter (fun v -> Printf.printf "%.1f\n" (float_of_int v /. 2.0)) ans
