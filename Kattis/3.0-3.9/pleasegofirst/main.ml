for _ = 1 to read_int () do
  ignore (read_line ());
  let m = Hashtbl.create 62 in
  let s = read_line () in
  String.iteri
    (fun i c ->
       match Hashtbl.find_opt m c with
       | None -> Hashtbl.add m c (i, 1)
       | Some (_, v) -> Hashtbl.replace m c (i, v + 1))
    s;
  let a = Hashtbl.to_seq_values m |> List.of_seq |> List.sort compare in
  let ans, _ =
    List.fold_left (fun (t, i) (j, x) -> t + ((j - i - x) * x), i + x) (0, -1) a
  in
  Printf.printf "%d\n" (ans * 5)
done
