let k = Scanf.scanf "%d\n" Fun.id in
let ds = Array.make_matrix k k 0 in
for u = 0 to k - 1 do
  for v = 0 to k - 1 do
    let d = Scanf.scanf "%d " Fun.id in
    ds.(u).(v) <- d
  done
done;
let g = Array.init 1000 (fun _ -> Dynarray.create ()) in
let n = ref k in
Dynarray.add_last g.(0) (1, !n, ds.(0).(1));
n := !n + ds.(0).(1) - 1;
for i = 2 to k - 1 do
  let rec loop u d1 =
    let x =
      Dynarray.find_map
        (fun (v, p, d) ->
           let d2 = ds.(v).(i) in
           if d2 = d1 + d
           then None
           else (
             let t = (d1 + d2 - d) / 2 in
             let h = d1 - t in
             Some (p + h - 1, t)))
        g.(u)
    in
    match x with
    | None ->
      Dynarray.add_last g.(u) (i, !n, d1);
      n := !n + d1 - 1
    | Some (u', d1') -> loop u' d1'
  in
  loop 0 ds.(0).(i)
done;
Printf.printf "%d\n" !n;
for u = 0 to !n - 1 do
  Dynarray.iter
    (fun (v, p, d) ->
       if d = 1
       then Printf.printf "%d %d\n" (u + 1) (v + 1)
       else (
         Printf.printf "%d %d\n" (u + 1) (p + 1);
         for i = p to p + d - 3 do
           Printf.printf "%d %d\n" (i + 1) (i + 2)
         done;
         Printf.printf "%d %d\n" (p + d - 1) (v + 1)))
    g.(u)
done
