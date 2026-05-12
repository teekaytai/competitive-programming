let () =
  let m = read_int () in
  ignore (read_int ());
  let c = read_int () in
  Printf.printf "%d\n" (m * c)
;;
