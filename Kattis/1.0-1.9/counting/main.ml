let n = read_int () in
Seq.iterate (Int.add n) n |> Seq.take 12 |> Seq.iter (Printf.printf "%d\n")
