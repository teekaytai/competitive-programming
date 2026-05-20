let p =
  Seq.init (read_int ()) (fun _ ->
    ignore (read_line ());
    read_int ())
  |> Seq.fold_left ( + ) 0
in
let i = Bool.to_int (p >= 0) + Bool.to_int (p > 0) in
print_endline [| "Nekad"; "Lagom"; "Usch, vinst" |].(i)
