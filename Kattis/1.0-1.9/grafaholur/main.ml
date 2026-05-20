Scanf.scanf "%f\n%f\n%f\n%f\n%f" (fun n h x m y ->
  Printf.printf "%f\n" (h *. n *. y /. x /. m))
