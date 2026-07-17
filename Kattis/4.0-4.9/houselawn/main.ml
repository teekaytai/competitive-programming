let x, m = Scanf.scanf "%d %d\n" (fun l m -> l, m) in
let a =
  List.init m (fun _ ->
    Scanf.scanf "%[^,],%d,%d,%d,%d\n" (fun n p c t r -> n, p, c, t, r))
  |> List.filter_map (fun (n, p, c, t, r) ->
    if c * t * 10080 >= x * (t + r) then Some (p, n) else None)
in
let mn = List.fold_left (fun acc (p, _) -> Int.min acc p) 10000000 a in
let b = List.filter (fun (p, _) -> Int.equal p mn) a in
if List.is_empty b
then print_endline "no such mower"
else List.iter (fun (_, n) -> print_endline n) b
