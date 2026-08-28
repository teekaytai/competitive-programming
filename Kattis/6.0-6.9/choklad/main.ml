let rec f arr h w =
  let x, h', w' =
    if h = 1 && w = 1
    then 1, 0, 0
    else if h mod 2 = 0 || (w mod 2 = 1 && h >= w)
    then h / 2 * w, (h + 1) / 2, w
    else w / 2 * h, h, (w + 1) / 2
  in
  if (not (Dynarray.is_empty arr)) && Dynarray.get_last arr = x
  then Dynarray.remove_last arr
  else Dynarray.add_last arr x;
  if h' > 0 then f arr h' w'
;;

let pack d b = (d lsl 1) + if b then 1 else 0
let unpack x = x asr 1, x land 1 = 1

let comb x1 x2 =
  let d1, b1 = unpack x1 in
  let d2, b2 = unpack x2 in
  pack (d2 + if b2 then -d1 else d1) (b1 <> b2)
;;

let uncomb x1 x2 =
  let d1, b1 = unpack x1 in
  let d2, b2 = unpack x2 in
  let b = b1 <> b2 in
  pack (d2 - if b then -d1 else d1) b
;;

let n = Scanf.scanf "%d" Fun.id in
let g = Array.init n (fun _ -> Dynarray.create ()) in
let ks = Array.make n false in
let mm = ref 0 in
for i = 0 to n - 1 do
  let h, w, k = Scanf.scanf "\n%d %d %d" (fun h w k -> h, w, k mod 2 = 1) in
  ks.(i) <- k;
  f g.(i) h w;
  mm := !mm + Dynarray.length g.(i)
done;
let aa = Array.make !mm 0 in
let aai = ref 0 in
Array.iteri
  (fun i xs ->
     Dynarray.iter
       (fun x ->
          aa.(!aai) <- pack x ks.(i);
          aai := !aai + 1)
       xs)
  g;
Array.fast_sort Int.compare aa;
let a = Dynarray.create () in
Dynarray.set_capacity a !mm;
let pr = ref 0 in
Array.iter
  (fun z ->
     let x, b = unpack z in
     if x = !pr
     then (
       if b
       then (
         let i = Dynarray.length a - 1 in
         Dynarray.set a i (Dynarray.get a i lxor 1)))
     else (
       Dynarray.add_last a z;
       pr := x))
  aa;
let m = Dynarray.length a in
let ps = Array.make (m + 1) 0 in
Dynarray.iteri (fun i z -> ps.(i + 1) <- comb ps.(i) (if z land 1 = 1 then z else 0)) a;
let ans =
  Array.fold_left
    (fun mn xs ->
       let res, last =
         Dynarray.fold_left
           (fun (acc, p) x ->
              let x2 = x lsl 1 in
              let lo = ref 0 in
              let hi = ref (m - 1) in
              while !lo < !hi do
                let mid = (!lo + !hi) / 2 in
                if Dynarray.get a mid >= x2 then hi := mid else lo := mid + 1
              done;
              let b = Dynarray.get a !lo land 1 = 1 in
              let z = pack (if b then 0 else x) (not b) in
              comb z (comb (uncomb ps.(!lo + 1) ps.(p + 1)) acc), !lo - 1)
           (0, m - 1)
           xs
       in
       let res = comb ps.(last + 1) res in
       Int.min mn (Int.abs (res asr 1)))
    (Int.abs (ps.(m) asr 1))
    g
in
Printf.printf "%d\n" ans
