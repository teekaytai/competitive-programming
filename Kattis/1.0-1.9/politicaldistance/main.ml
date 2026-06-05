Scanf.scanf "%Ld %Ld\n%Ld %Ld" (fun x1 y1 x2 y2 ->
  let dx = Int64.sub x2 x1 in
  let dy = Int64.sub y2 y1 in
  Printf.printf "%Ld\n" (Int64.add (Int64.mul dx dx) (Int64.mul dy dy)))
