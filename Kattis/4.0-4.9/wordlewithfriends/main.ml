let f k v w =
  let res = Array.make 5 '-' in
  let cs = Hashtbl.create 5 in
  for i = 0 to 4 do
    if k.[i] = w.[i] then res.(i) <- 'G' else Hashtbl.add cs w.[i] ()
  done;
  for i = 0 to 4 do
    if res.(i) = '-' && Hashtbl.mem cs k.[i]
    then (
      res.(i) <- 'Y';
      Hashtbl.remove cs k.[i])
  done;
  res = v
;;

let n, q = Scanf.scanf "%d %d\n" (fun n q -> n, q) in
let a =
  List.init n (fun _ ->
    Scanf.scanf "%s %s\n" (fun k v -> k, String.to_seq v |> Array.of_seq))
in
for _ = 1 to q do
  let w = Scanf.scanf "%s\n" Fun.id in
  if List.for_all (fun (k, v) -> f k v w) a then print_endline w
done
