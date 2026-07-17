let mo = 1000000007
let rec modinv x = if x <= 1 then x else mo - (mo / x * modinv (mo mod x) mod mo)
let moddiv a b = a * modinv (b mod mo) mod mo

let modpow b p =
  let rec helper b p acc =
    if p = 0
    then acc
    else (
      let acc2 = if p land 1 = 1 then b * acc mod mo else acc in
      helper (b * b mod mo) (p / 2) acc2)
  in
  helper b p 1
;;

let rec gcd a b = if b = 0 then a else gcd b (a mod b);;

let n, m, c = Scanf.scanf "%d %d %d" (fun n m c -> n, m, c) in
let k = modpow c (n * n) in
let ans = ref 0 in
for i = 0 to m - 1 do
  let g = gcd i m in
  ans := (!ans + modpow k g) mod mo
done;
Printf.printf "%d\n" (moddiv !ans m)
