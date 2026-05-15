let () =
  let x, y = Scanf.scanf "%d ? %d" (fun x y -> x, y) in
  print_endline
    [| "<"; "Goggi svangur!"; ">" |].(Bool.to_int (x > y) + Bool.to_int (x >= y))
;;
