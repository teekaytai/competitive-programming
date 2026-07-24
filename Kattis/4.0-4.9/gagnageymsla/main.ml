let mo = 1000000007
let rec modinv x = if x <= 1 then x else mo - (mo / x * modinv (mo mod x) mod mo)
let moddiv a b = a * modinv (b mod mo) mod mo;;

let n, m = Scanf.scanf "%d %d\n" (fun n m -> n, m) in
let can = ref false in
let memo = Array.make_matrix 5001 71 None in
let rec f n x =
  if n = 0
  then (
    can := true;
    x, 1)
  else (
    match memo.(n).(x) with
    | Some (t, c) -> t, c
    | None ->
      let i = ref 1 in
      while !i * !i <= x do
        i := !i + 1
      done;
      let t = ref 0 in
      let c = ref 0 in
      while (!i * !i) - x <= Int.min n m do
        let dt, dc = f (n - ((!i * !i) - x)) !i in
        t := (!t + dt) mod mo;
        c := (!c + dc) mod mo;
        i := !i + 1
      done;
      memo.(n).(x) <- Some (!t, !c);
      !t, !c)
in
let t, c = f n 0 in
Printf.printf "%d\n" (if !can then moddiv t c else -1)
