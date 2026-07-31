let rec f h s t i j =
  if i = String.length s || j == String.length t
  then 0
  else (
    match h.(i).(j) with
    | -1 ->
      let res =
        if Char.equal s.[i] t.[j]
        then 1 + f h s t (i + 1) (j + 1)
        else Int.max (f h s t (i + 1) j) (f h s t i (j + 1))
      in
      h.(i).(j) <- res;
      res
    | x -> x)
;;

for _ = 1 to read_int () do
  let s = read_line () in
  let t = read_line () in
  let h = Array.make_matrix (String.length s) (String.length t) (-1) in
  Printf.printf "%d\n" (f h s t 0 0)
done
