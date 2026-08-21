module P = struct
  type t = int * int

  let compare (x1, _) (x2, _) = Int.compare x1 x2
end

module MinPQ = Pqueue.MakeMin (P);;

let exception Impossible in
try
  let n, m, p = Scanf.scanf "%d %d %d " (fun n m p -> n, m, p) in
  let a = Array.make n true in
  for _ = 1 to p do
    let v = Scanf.scanf "%d " Fun.id in
    a.(v - 1) <- false
  done;
  if p = n
  then
    if m <> n * (n - 1) / 2
    then raise Impossible
    else (
      let ans =
        Seq.init m (fun _ -> Scanf.scanf "%d %d %d\n" (fun _ _ w -> w))
        |> Seq.fold_left ( + ) 0
      in
      Printf.printf "%d\n" ans)
  else (
    let inf = 100000000000 in
    let g = Array.init n (fun _ -> Dynarray.create ()) in
    let mns = Array.map (fun b -> if b then 0 else inf) a in
    for _ = 1 to m do
      let u, v, w = Scanf.scanf "%d %d %d\n" (fun u v w -> u - 1, v - 1, w) in
      if a.(u) <> a.(v)
      then if a.(u) then mns.(v) <- min mns.(v) w else mns.(u) <- min mns.(u) w
      else if a.(u)
      then (
        Dynarray.add_last g.(u) (v, w);
        Dynarray.add_last g.(v) (u, w))
    done;
    let ans = ref (Array.fold_left ( + ) 0 mns) in
    if !ans >= inf
    then raise Impossible
    else (
      let s = Array.find_index Fun.id a |> Option.get in
      let ds = Array.make n inf in
      ds.(s) <- 0;
      let unseen = ref (n - p) in
      let pq = MinPQ.create () in
      MinPQ.add pq (0, s);
      while !unseen > 0 do
        match MinPQ.pop_min pq with
        | None -> raise Impossible
        | Some (d, u) ->
          if d = ds.(u)
          then (
            ans := !ans + d;
            unseen := !unseen - 1;
            ds.(u) <- 0;
            Dynarray.iter
              (fun (v, w) ->
                 if w < ds.(v)
                 then (
                   ds.(v) <- w;
                   MinPQ.add pq (w, v)))
              g.(u))
      done;
      Printf.printf "%d\n" !ans))
with
| Impossible -> print_endline "impossible"
