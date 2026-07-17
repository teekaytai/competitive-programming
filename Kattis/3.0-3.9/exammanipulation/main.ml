let n, m = Scanf.sscanf (read_line ()) "%d %d" (fun n m -> n, m) in
let a = List.init n (fun _ -> read_line ()) in
Seq.init (1 lsl m) (fun x ->
  List.fold_left
    (fun mn s ->
       let t, _ =
         String.fold_left
           (fun (acc, v) c ->
              acc + Bool.to_int (Bool.to_int (c = 'T') = v land 1), v lsr 1)
           (0, x)
           s
       in
       Int.min mn t)
    m
    a)
|> Seq.fold_left Int.max 0
|> Printf.printf "%d\n"
