Seq.init (read_int ()) (fun _ -> read_int () mod 2)
|> Seq.fold_left ( + ) 0
|> Printf.printf "%d\n"
