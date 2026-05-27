Seq.init (read_int ()) (fun _ ->
  ignore (read_int ());
  String.split_on_char ' ' (read_line ()) |> List.map int_of_string)
|> Seq.iter (fun dists ->
  let s = List.fold_left ( + ) 0 dists in
  let ans =
    if s mod 2 <> 0
    then "IMPOSSIBLE"
    else (
      let inf = s in
      let h = s / 2 in
      let init = Array.init (h + 1) (fun i -> if i = 0 then 0, -1 else inf, -1) in
      let last_dp, dps =
        List.fold_left_map
          (fun dp d ->
             let dp2 =
               Array.init (h + 1) (fun i ->
                 let l = if i >= d then max i (fst dp.(i - d)), i - d else inf, -1 in
                 let r = if i + d <= h then fst dp.(i + d), i + d else inf, -1 in
                 min l r)
             in
             dp2, dp2)
          init
          dists
      in
      if fst last_dp.(0) = inf
      then "IMPOSSIBLE"
      else (
        let _, directions =
          List.fold_right
            (fun dp (i, directions) ->
               let j = snd dp.(i) in
               j, (if i > j then 'U' else 'D') :: directions)
            dps
            (0, [])
        in
        String.of_seq (List.to_seq directions)))
  in
  print_endline ans)
