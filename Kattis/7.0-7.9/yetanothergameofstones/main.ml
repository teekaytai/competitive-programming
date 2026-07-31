for _ = 1 to read_int () do
  ignore (read_int ());
  let a = read_line () |> String.split_on_char ' ' |> List.map int_of_string in
  let b = read_line () |> String.split_on_char ' ' |> List.map int_of_string in
  let xor_sum, blocked_one, cons_sum, cons_val =
    List.fold_left2
      (fun (xor_sum, blocked_one, cons_sum, cons_val) v c ->
         ( xor_sum lxor v
         , blocked_one || (v = 1 && c = 2)
         , (cons_sum + if v > 1 && c > 0 then 1 else 0)
         , if v > 1 && c > 0 then v, c else cons_val ))
      (0, false, 0, (0, 0))
      a
      b
  in
  let v, c = cons_val in
  let v2 = v lxor xor_sum in
  let winnable =
    xor_sum > 0
    && (not blocked_one)
    && (cons_sum = 0
        || (cons_sum = 1
            && ((v2 = 0 && v mod 2 = c mod 2) || (v2 = 1 && c = 1 && v mod 2 = 0))))
  in
  print_endline (if winnable then "Alice" else "Bob")
done
