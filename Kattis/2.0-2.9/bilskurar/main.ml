let r () = String.split_on_char ' ' (read_line ()) |> List.map int_of_string;;

let n = read_int () in
let o = Array.make (n + 1) 0 in
let p = r () in
List.iteri (fun i x -> o.(x) <- i) p;
let a = r () |> Array.of_list |> Array.map (fun x -> o.(x)) in
let rec f a aux lo hi =
  if hi - lo <= 1
  then 0
  else (
    let mid = (lo + hi) / 2 in
    let tl = f a aux lo mid in
    let tr = f a aux mid hi in
    let tm = ref 0 in
    let i1 = ref lo in
    let i2 = ref mid in
    for i = lo to hi - 1 do
      if Int.equal !i2 hi || ((not (Int.equal !i1 mid)) && a.(!i1) <= a.(!i2))
      then (
        aux.(i) <- a.(!i1);
        i1 := !i1 + 1)
      else (
        aux.(i) <- a.(!i2);
        i2 := !i2 + 1;
        tm := !tm + (mid - !i1))
    done;
    for i = lo to hi - 1 do
      a.(i) <- aux.(i)
    done;
    tl + tr + !tm)
in
let aux = Array.make n 0 in
let ans = f a aux 0 n in
Printf.printf "%d\n" ans
