module P = struct
  type t = int * int

  let compare (x1, _) (x2, _) = Int.compare x1 x2
end

module MinPQ = Pqueue.MakeMin (P)

let r () = Scanf.scanf "%d " Fun.id;;

let n = r () in
let m = r () in
let s1 = r () in
let s2 = r () in
let g = Array.init n (fun _ -> Dynarray.create ()) in
for _ = 1 to m do
  let c = r () in
  let k = r () in
  let vs = Array.init k (fun _ -> r ()) in
  let t = ref 0 in
  for i = 0 to k - 2 do
    let w = r () in
    Dynarray.add_last g.(vs.(i)) (vs.(i + 1), c, !t, w);
    t := (!t + w) mod c
  done
done;
let f s =
  let ds = Array.make n Int.max_int in
  ds.(s) <- 0;
  let pq = MinPQ.create () in
  MinPQ.add pq (0, s);
  let rec loop () =
    match MinPQ.pop_min pq with
    | None -> ()
    | Some (d, u) ->
      if ds.(u) = d
      then
        Dynarray.iter
          (fun (v, c, t, w) ->
             let r = (t - d) mod c in
             let d2 = d + (if r >= 0 then r else r + c) + w in
             if d2 < ds.(v)
             then (
               ds.(v) <- d2;
               MinPQ.add pq (d2, v)))
          g.(u);
      loop ()
  in
  loop ();
  ds
in
let ds1 = f s1 in
let ds2 = f s2 in
let res =
  Seq.fold_left2
    (fun acc d1 d2 -> Int.min acc (Int.max d1 d2))
    Int.max_int
    (Array.to_seq ds1)
    (Array.to_seq ds2)
in
if res < Int.max_int then Printf.printf "%d\n" res else print_endline "NO COFFEE FOR YOU"
