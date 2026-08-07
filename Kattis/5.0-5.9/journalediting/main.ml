let ctz x =
  let rec loop x acc = if x = 1 then acc else loop (x lsr 1) (acc + 1) in
  loop x 0
;;

let read_int () = Scanf.scanf "%d " Fun.id;;

let n = read_int () in
let g = Array.init n (fun _ -> Dynarray.create ()) in
for i = 0 to n - 1 do
  let p = read_int () in
  for _ = 1 to p do
    let w = read_int () in
    let k = read_int () in
    let m = Seq.init k (fun _ -> 1 lsl read_int ()) |> Seq.fold_left ( + ) 0 in
    Dynarray.add_last g.(i) (w, m)
  done
done;
let inf = 1 lsl 30 in
let dp = Array.make (1 lsl n) inf in
dp.(0) <- 0;
let ans = ref inf in
for i = 1 to (1 lsl n) - 1 do
  let ma = ref i in
  while !ma > 0 do
    let b = !ma land - !ma in
    ma := !ma - b;
    let j = i - b in
    let x = dp.(j) in
    if x < inf
    then (
      let bi = ctz b in
      let mn =
        Dynarray.fold_left
          (fun acc (w, m) -> if m land j = m then min acc w else acc)
          inf
          g.(bi)
      in
      dp.(i) <- min dp.(i) (x + mn))
  done;
  if i land 1 > 0 then ans := Int.min !ans dp.(i)
done;
Printf.printf "%d\n" !ans
