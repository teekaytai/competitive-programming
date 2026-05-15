let () =
  let ans = Scanf.scanf "%d\n%d" (fun x y -> lnot ~-x * y) in
  Printf.printf "%d\n" ans
;;
