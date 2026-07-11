let rec f seen a =
  match a with
  | [] -> ()
  | x :: xs ->
    List.iter (fun y -> seen.(y - x) <- seen.(y - x) + 1) xs;
    f seen xs
;;

let rec main () =
  match In_channel.input_line stdin with
  | None -> ()
  | Some s ->
    let a =
      String.split_on_char ' ' s |> List.map int_of_string |> List.sort Int.compare
    in
    let l = List.length a in
    let n = List.nth a (l - 1) in
    let seen = Array.make (n + 1) 0 in
    f seen a;
    if Array.exists (fun c -> c > 1) seen
    then print_endline "not a ruler"
    else if l * (l - 1) / 2 = n
    then print_endline "perfect"
    else (
      print_string "missing";
      Array.iteri (fun i c -> if i > 0 && c < 1 then Printf.printf " %d" i) seen;
      print_newline ());
    main ()
;;

main ()
