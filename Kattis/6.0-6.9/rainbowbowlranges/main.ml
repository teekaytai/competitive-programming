let n, m = Scanf.scanf "%d %d\n" (fun n m -> n, m) in
let a = List.init m (fun _ -> Scanf.scanf "%d\n" Fun.id) |> List.sort compare in
let ans, _ =
  List.fold_right
    (fun x (t, c) ->
       if x = n
       then t, c
       else (
         let d = n - x + 1 in
         if c > d then t + 1, c - d else t, c))
    (List.tl a)
    (1, List.hd a)
in
Printf.printf "%d\n" ans
