let rec square lst acc =
  match lst with
  | [] -> acc
  | x :: xs -> square xs (List.map (fun x2 -> x, x2) xs @ acc)
;;

let rec cube lst acc =
  match lst with
  | [] -> acc
  | x :: xs -> cube xs (List.map (fun (x2, x3) -> x, x2, x3) (square xs []) @ acc)
;;

let det (a, b, c) (d, e, f) (g, h, i) =
  (a * ((e * i) - (f * h))) - (b * ((d * i) - (f * g))) + (c * ((d * h) - (e * g)))
;;

let a = [ 1, 1, 1; 1, 1, 2; 1, 2, 1; 2, 1, 1; 1, 2, 3 ] in
let m =
  List.map
    (fun (x, y, z) ->
       Printf.printf "%d %d %d\n%!" x y z;
       (x, y, z), read_int ())
    a
in
let h = Hashtbl.create 7 in
List.iter
  (fun ((r1, c1), (r2, c2), (r3, c3)) ->
     let d = det r1 r2 r3 in
     let r11, r12, r13 = r1 in
     let r21, r22, r23 = r2 in
     let r31, r32, r33 = r3 in
     let dx = det (c1, r12, r13) (c2, r22, r23) (c3, r32, r33) in
     let dy = det (r11, c1, r13) (r21, c2, r23) (r31, c3, r33) in
     let dz = det (r11, r12, c1) (r21, r22, c2) (r31, r32, c3) in
     let res = dx / d, dy / d, dz / d in
     match Hashtbl.find_opt h res with
     | None -> Hashtbl.add h res 1
     | Some v -> Hashtbl.replace h res (v + 1))
  (cube m []);
let _, (x, y, z) =
  Hashtbl.fold (fun t v (mx, ans) -> if v > mx then v, t else mx, ans) h (0, (0, 0, 0))
in
Printf.printf "%d %d %d\n%!" x y z
