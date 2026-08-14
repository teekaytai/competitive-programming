let n = Scanf.scanf "%d\n" Fun.id in
let g =
  Array.init n (fun i ->
    let r = Scanf.scanf "%d " Fun.id in
    let u = (i + r) mod n in
    let v = (i + n - r) mod n in
    u, v)
in
let rg = Array.init n (fun _ -> Dynarray.create ()) in
let cs = Array.make n 0 in
Array.iteri
  (fun i (u, v) ->
     Dynarray.add_last rg.(u) i;
     Dynarray.add_last rg.(v) i;
     cs.(u) <- cs.(u) + 1;
     cs.(v) <- cs.(v) + 1)
  g;
let st = Dynarray.create () in
let used = Array.make n false in
let ans = Array.make n None in
let exception Impossible in
let f i j =
  let res, k =
    let u, v = g.(i) in
    if u = j then 'L', v else 'R', u
  in
  ans.(i) <- Some res;
  used.(j) <- true;
  cs.(k) <- cs.(k) - 1;
  if not used.(k)
  then if cs.(k) = 0 then raise Impossible else if cs.(k) = 1 then Dynarray.add_last st k;
  res
in
try
  Array.iteri
    (fun i c ->
       if c = 0 then raise Impossible;
       if c = 1 then Dynarray.add_last st i)
    cs;
  for i = 0 to n - 1 do
    while not (Dynarray.is_empty st) do
      let j = Dynarray.pop_last st in
      let k = Dynarray.find_opt (fun k -> Option.is_none ans.(k)) rg.(j) |> Option.get in
      ignore (f k j)
    done;
    let res =
      match ans.(i) with
      | None -> f i (fst g.(i))
      | Some x -> x
    in
    print_char res
  done;
  print_newline ()
with
| Impossible -> print_endline "no dance"
