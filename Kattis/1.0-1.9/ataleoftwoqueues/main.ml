ignore (read_line ());
let f () =
  read_line ()
  |> String.split_on_char ' '
  |> List.map int_of_string
  |> List.fold_left ( + ) 0
in
let t1 = f () in
let t2 = f () in
let cmp = t1 - t2 in
print_endline (if cmp < 0 then "left" else if cmp > 0 then "right" else "either")
