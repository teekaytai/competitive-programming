let () =
  let xr, yr = Scanf.scanf "%d %d\n" (fun x y -> x, y) in
  let xp, yp = Scanf.scanf "%d %d\n" (fun x y -> x, y) in
  Printf.printf "%d\n" (Bool.to_int (xr != xp) + Bool.to_int (yr != yp))
;;
