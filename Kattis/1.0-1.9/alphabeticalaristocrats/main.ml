let f s = String.to_seq s |> Seq.drop_while (fun c -> c < 'A' || c > 'Z') |> String.of_seq
;;

let n = read_int () in
List.init n (fun _ -> read_line ())
|> List.map (fun s -> f s, s)
|> List.sort compare
|> List.iter (fun (_, s) -> print_endline s)
