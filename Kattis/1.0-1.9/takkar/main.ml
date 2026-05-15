let () =
  let x = read_int () in
  let y = read_int () in
  let i = Bool.to_int (x > y) + Bool.to_int (x >= y) in
  print_endline [| "FAKE NEWS!"; "WORLD WAR 3!"; "MAGA!" |].(i)
;;
