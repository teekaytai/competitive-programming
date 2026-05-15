let n = read_int () in
Seq.init n (fun _ -> read_int ()) |> Seq.fold_left ( + ) 0 |> Printf.printf "%d\n"
