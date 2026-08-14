let _, a, b, c = Scanf.sscanf (read_line ()) "%d %d %d %d" (fun n a b c -> n, a, b, c) in
let l = read_line () |> String.split_on_char ' ' |> List.map int_of_string in
let arr = Array.make 303 true in
let m =
  List.fold_left
    (fun t x ->
       let t2 = t + x in
       arr.(t2) <- false;
       t2)
    0
    l
in
arr.(m) <- true;
arr.(m + 1) <- false;
arr.(m + 2) <- false;
let h = Hashtbl.create 4500000 in
let rec f i a b c =
  i = m
  || (i < m
      &&
      match Hashtbl.find_opt h (i, a, b) with
      | Some res -> res
      | None ->
        let res =
          (a > 0 && arr.(i + 1) && f (i + 1) (a - 1) b c)
          || (b > 0 && arr.(i + 2) && f (i + 2) a (b - 1) c)
          || (c > 0 && arr.(i + 3) && f (i + 3) a b (c - 1))
        in
        Hashtbl.add h (i, a, b) res;
        res)
in
print_endline (if f 0 a b c then "YES" else "NO")
