let rec f x =
  if x < 10
  then x
  else string_of_int x |> String.fold_left (fun acc d -> acc + Char.code d - 48) 0 |> f
;;

Printf.printf "%d\n" (f (read_int ()))
