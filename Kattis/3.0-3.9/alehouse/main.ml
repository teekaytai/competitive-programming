let () =
  let n, k = Scanf.scanf "%d %d\n" (fun n k -> n, k) in
  let events =
    List.init n (fun _ -> Scanf.scanf "%d %d\n" (fun l r -> l, r))
    |> List.concat_map (fun (l, r) -> [ l, 1; r + k + 1, -1 ])
    |> List.sort compare
  in
  let ans, _ =
    List.fold_left
      (fun (mx, ps) (_, d) ->
         let ps2 = ps + d in
         Int.max mx ps2, ps2)
      (0, 0)
      events
  in
  Printf.printf "%d\n" ans
;;
