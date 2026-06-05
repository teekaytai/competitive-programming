for _ = 1 to read_int () do
  let k, n = Scanf.scanf "%d %s\n" (fun k n -> k, n) in
  let ans = String.map (fun d -> Char.chr (((Char.code d - 48 + k) mod 10) + 48)) n in
  print_endline ans
done
