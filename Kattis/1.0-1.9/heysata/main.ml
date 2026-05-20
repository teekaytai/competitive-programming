ignore (read_int ());
let c = (read_line ()).[0] in
print_endline
  (if String.contains (read_line ()) c
   then "Unnar fann hana!"
   else "Unnar fann hana ekki!")
