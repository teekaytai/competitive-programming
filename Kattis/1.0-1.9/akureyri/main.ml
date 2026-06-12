let m = Hashtbl.create 10000 in
for _ = 1 to read_int () do
  ignore (read_line ());
  let k = read_line () in
  match Hashtbl.find_opt m k with
  | None -> Hashtbl.add m k 1
  | Some v -> Hashtbl.replace m k (v + 1)
done;
Hashtbl.iter (fun k v -> Printf.printf "%s %d\n" k v) m
