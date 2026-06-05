module IntSet = Set.Make (Int);;

let n, k = Scanf.sscanf (read_line ()) "%d %d" (fun n k -> n, k) in
Seq.init n (fun _ -> read_int ())
|> IntSet.of_seq
|> IntSet.cardinal
|> Int.min k
|> Printf.printf "%d\n"
