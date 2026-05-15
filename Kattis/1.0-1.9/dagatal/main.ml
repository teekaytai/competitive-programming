let () =
  let m = read_int () in
  Printf.printf "%d\n" (if m == 2 then 28 else 30 + (m mod 2 lxor Bool.to_int (m > 7)))
;;
