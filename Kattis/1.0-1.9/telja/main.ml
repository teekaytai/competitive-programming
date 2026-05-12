let () =
  let n = read_int () in
  Seq.ints 1 |> Seq.take n |> Seq.iter (Printf.printf "%d\n")
;;
