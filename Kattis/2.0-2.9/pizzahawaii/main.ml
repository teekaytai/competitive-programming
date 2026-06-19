let f h b =
  let a = List.tl (String.split_on_char ' ' (read_line ())) in
  List.iter
    (fun k ->
       match Hashtbl.find_opt h k with
       | None -> Hashtbl.add h k b
       | Some v -> Hashtbl.replace h k (v + b))
    a
;;

for _ = 1 to read_int () do
  let n = read_int () in
  let h1 = Hashtbl.create 1200 in
  let h2 = Hashtbl.create 1200 in
  for i = 0 to n - 1 do
    ignore (read_line ());
    let b = 1 lsl i in
    f h1 b;
    f h2 b
  done;
  let m = Hashtbl.create 1200 in
  Hashtbl.iter
    (fun k v ->
       match Hashtbl.find_opt m v with
       | None -> Hashtbl.add m v [ k ]
       | Some ss -> Hashtbl.replace m v (k :: ss))
    h2;
  Hashtbl.iter (fun k ss -> Hashtbl.replace m k (List.sort String.compare ss)) m;
  Hashtbl.to_seq_keys h1
  |> List.of_seq
  |> List.sort String.compare
  |> List.iter (fun k ->
    let v = Hashtbl.find h1 k in
    match Hashtbl.find_opt m v with
    | None -> ()
    | Some ss -> List.iter (fun s -> Printf.printf "(%s, %s)\n" k s) ss);
  print_newline ()
done
