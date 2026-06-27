let n, m, r = Scanf.scanf "%d %d %d\n" (fun n m r -> n, m, r) in
let ps = List.init n (fun _ -> Scanf.scanf "%d %d\n" (fun x y -> x, y)) in
let ls = List.init m (fun _ -> Scanf.scanf "%d %d %d\n" (fun a b c -> a, b, c)) in
let rf = float_of_int r in
let r2 = rf *. rf in
let t, _ =
  List.fold_left
    (fun (acc, ls2) (a1, b1, c1) ->
       let ls2 = List.tl ls2 in
       let s =
         List.fold_left
           (fun acc (a2, b2, c2) ->
              let det = (a1 * b2) - (a2 * b1) in
              if det = 0
              then acc
              else (
                let x = float_of_int ((b1 * c2) - (b2 * c1)) /. float_of_int det in
                let y = float_of_int ((c1 * a2) - (c2 * a1)) /. float_of_int det in
                let v = if (x *. x) +. (y *. y) < r2 then 1 else 0 in
                acc + v))
           0
           ls2
       in
       acc + s, ls2)
    (m + 1, ls)
    ls
in
let h =
  List.to_seq ps
  |> Seq.map (fun (x, y) ->
    let k =
      List.fold_left
        (fun acc (a, b, c) ->
           let v = if (a * x) + (b * y) + c > 0 then 1 else 0 in
           (acc * 2) + v)
        0
        ls
    in
    k, ())
  |> Hashtbl.of_seq
in
print_endline (if t = n && Hashtbl.length h = n then "yes" else "no")
