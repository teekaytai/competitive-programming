let n, m, _ = Scanf.sscanf (read_line ()) "%d %d %d" (fun n m k -> n, m, k) in
let q =
  read_line ()
  |> String.split_on_char ' '
  |> List.to_seq
  |> Seq.map (fun x ->
    let v = int_of_string x - 1 in
    v, v)
  |> Queue.of_seq
in
let g = Array.make n [] in
for _ = 1 to m do
  let u, v = Scanf.scanf "%d %d\n" (fun u v -> u - 1, v - 1) in
  g.(u) <- v :: g.(u);
  g.(v) <- u :: g.(v)
done;
let ds = Array.make n (-1) in
let seen = Array.make n (-1) in
let d = ref 0 in
while not (Queue.is_empty q) do
  d := !d + 1;
  for _ = 1 to Queue.length q do
    let u, p = Queue.take q in
    List.iter
      (fun v ->
         if v <> p && seen.(v) <> -2 && seen.(v) <> p
         then (
           if ds.(v) = -1
           then (
             seen.(v) <- p;
             ds.(v) <- !d)
           else seen.(v) <- -2;
           Queue.add (v, p) q))
      g.(u)
  done
done;
Array.iter (Printf.printf "%d ") ds;
print_newline ()
