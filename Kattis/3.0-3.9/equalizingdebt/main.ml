let n = Scanf.scanf "%d\n" Fun.id in
let ma = Hashtbl.create 200 in
for _ = 1 to n do
  let u, v, x = Scanf.scanf "%s %s %d\n" (fun u v x -> u, v, x) in
  (match Hashtbl.find_opt ma u with
   | None -> Hashtbl.add ma u x
   | Some y -> Hashtbl.replace ma u (y + x));
  match Hashtbl.find_opt ma v with
  | None -> Hashtbl.add ma v (-x)
  | Some y -> Hashtbl.replace ma v (y - x)
done;
let a, b = Hashtbl.to_seq ma |> List.of_seq |> List.partition (fun (_, v) -> v < 0) in
let rec f a b =
  match a, b with
  | _, (_, v) :: b2 when v = 0 -> f a b2
  | (k1, v1) :: tl1, (k2, v2) :: tl2 ->
    let mn = Int.min (-v1) v2 in
    Printf.printf "%s %s %d\n" k1 k2 mn;
    let a2 = if -v1 = mn then tl1 else (k1, v1 + mn) :: tl1 in
    let b2 = if v2 = mn then tl2 else (k2, v2 - mn) :: tl2 in
    f a2 b2
  | _ -> ()
in
f a b;
print_endline "settled"
