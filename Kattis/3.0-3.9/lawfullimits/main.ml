module P = struct
  type t = float * int

  let compare = compare
end

module PSet = Set.Make (P);;

let n, m, t = Scanf.scanf "%d %d %f\n" (fun n m t -> n, m, t) in
let g = Array.make n [] in
for _ = 1 to m do
  let u, v, w, a, b =
    Scanf.scanf "%d %d %f %f %f\n" (fun u v w a b -> u - 1, v - 1, w, a, b)
  in
  g.(u) <- (v, w, a, b) :: g.(u);
  g.(v) <- (u, w, a, b) :: g.(v)
done;
let ds = Array.make n Float.infinity in
ds.(0) <- 0.0;
let pq = ref (PSet.singleton (0.0, 0)) in
let reached = ref false in
while not !reached do
  let d, u = PSet.min_elt !pq in
  pq := PSet.remove (d, u) !pq;
  if u = n - 1
  then (
    Printf.printf "%.9f\n" d;
    reached := true)
  else
    List.iter
      (fun (v, w, a, b) ->
         let x = Float.min w (a *. Float.max (t -. d) 0.0) in
         let d2 = d +. (x /. a) +. ((w -. x) /. b) in
         if d2 < ds.(v)
         then (
           if Float.is_finite ds.(v) then pq := PSet.remove (ds.(v), v) !pq;
           ds.(v) <- d2;
           pq := PSet.add (d2, v) !pq))
      g.(u)
done
