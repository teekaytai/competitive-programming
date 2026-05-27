let n, _ = Scanf.sscanf (read_line ()) "%d %d" (fun n m -> n, m) in
let ans =
  Seq.init n (fun r -> r, read_line ())
  |> Seq.flat_map (fun (r, row) ->
    String.to_seqi row
    |> Seq.filter_map (fun (c, cell) ->
      if Char.equal cell '*' then Some (r + 1, c + 1) else None))
  |> List.of_seq
in
Printf.printf "%d\n" (List.length ans);
List.iter (fun (r, c) -> Printf.printf "%d %d\n" r c) ans
