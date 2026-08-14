for _ = 1 to Scanf.scanf "%d" Fun.id do
  print_endline "5 1 5 6";
  while Scanf.scanf " %s" Fun.id = "MOVE" do
    let r1, c1, r2, c2 = Scanf.scanf " %d %d %d %d" (fun r1 c1 r2 c2 -> r1, c1, r2, c2) in
    Printf.printf "%d %d %d %d\n%!" (Int.max (5 - r2) 1) (7 - c2) (5 - r1) (7 - c1)
  done
done
