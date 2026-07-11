let e2 = [ ":)"; "xD" ]
let e3 = [ ":-)"; ":-("; ";-)"; "^_^"; "-_-"; "^o^"; "^^;" ]
let e4 = "(..)"
let t = "A:;-()xD^-_o."

let rec f s n i acc =
  if i >= n - 1
  then acc
  else if i + 2 <= n && List.mem (String.sub s i 2) e2
  then f s n (i + 2) (acc + 1)
  else if i + 3 <= n && List.mem (String.sub s i 3) e3
  then f s n (i + 3) (acc + 2)
  else if i + 4 <= n && String.equal (String.sub s i 4) e4
  then f s n (i + 4) (acc + 3)
  else f s n (i + 1) acc
;;

let s = read_line () in
let n = String.length s in
let a = String.to_seq s |> List.of_seq |> List.sort_uniq Char.compare in
let mn, mx =
  List.fold_left
    (fun (mn, mx) x ->
       String.fold_left
         (fun (mn, mx) y ->
            let s2 = String.map (fun c -> if c = x then y else c) s in
            let v = f s2 n 0 0 in
            Int.min mn v, Int.max mx v)
         (mn, mx)
         t)
    (1000, 0)
    ('\000' :: a)
in
Printf.printf "%d %d\n" (n - mx) (n - mn)
