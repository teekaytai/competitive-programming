let n, m = Scanf.scanf "%d %d\n" (fun n m -> n, m) in
let g = Array.make n [] in
for _ = 1 to m do
  let u, v = Scanf.scanf "%d %d\n" (fun u v -> u - 1, v - 1) in
  g.(u) <- v :: g.(u)
done;
let s, t = Scanf.scanf "%d %d\n" (fun s t -> s - 1, t - 1) in
let seen1 = Array.make n false in
let seen2 = Array.make n false in
let rec dfs seen u p =
  seen.(u) <- true;
  List.iter (fun v -> if (not seen.(v)) && v <> p then dfs seen v u) g.(u)
in
dfs seen1 s (-1);
dfs seen2 t (-1);
let idx =
  Seq.zip (Array.to_seq seen1) (Array.to_seq seen2)
  |> Seq.mapi (fun i p -> i, p)
  |> Seq.find (fun (_, (b1, b2)) -> b1 && b2)
in
match idx with
| None -> print_endline "no"
| Some (i, _) -> Printf.printf "yes\n%d\n" (i + 1)
