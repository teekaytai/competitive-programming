for _ = 1 to read_int () do
  let a = String.split_on_char ' ' (read_line ()) in
  let b, _, _, _, _ =
    List.fold_left
      (fun (acc, p1, p2, p3, p4) x ->
         acc && Int.equal (int_of_string x) p1, p2, p3, p4, p1 + p2 + p3 + p4)
      (true, 0, 1, 2, 3)
      a
  in
  print_endline (if b then "NAUTILUS" else "SNAIL")
done
