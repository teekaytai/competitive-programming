let n = read_int () in
let cs = List.init n (fun _ -> String.index "BOPGRY" (read_line ()).[0]) in
let a = Array.make 6 (-1) in
List.iteri (fun i c -> a.(c) <- i) cs;
let seen = Array.make 6 false in
let t = Array.fold_left (fun acc j -> acc + Bool.to_int (j >= 0)) 0 a in
let ans, _, _, _ =
  List.fold_left
    (fun (x, seen, t, i) c ->
       seen.(c) <- true;
       let s = Array.fold_left (fun acc b -> acc + Bool.to_int b) 0 seen in
       if not (Int.equal s t)
       then x, seen, t, i + 1
       else (
         let t2 = Array.fold_left (fun acc j -> acc + Bool.to_int (j > i)) 0 a in
         for i = 0 to 5 do
           seen.(i) <- false
         done;
         x + 1, seen, t2, i + 1))
    (0, seen, t, 0)
    cs
in
Printf.printf "%d\n" ans
