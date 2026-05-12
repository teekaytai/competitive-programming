let () =
  let mx = Int.max (Int.max (read_int ()) (read_int ())) (read_int ()) in
  let i = Bool.to_int (mx >= 90) + Bool.to_int (mx > 90) in
  print_endline ([| "Spetsig"; "Ratvinklig"; "Trubbig" |].(i) ^ " Triangel")
;;
