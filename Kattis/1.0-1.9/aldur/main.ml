let () =
  Seq.init (read_int ()) (fun _ -> read_int ())
  |> Seq.fold_left Int.min Int.max_int
  |> Printf.printf "%d\n"
;;
