module P = struct
  type t = int * int

  let compare = compare
end

module PSet = Set.Make (P);;

let _, k = Scanf.scanf "%d %d" (fun n k -> n, k) in
let pq = Seq.init k (fun i -> Scanf.scanf " %d" (fun x -> x, i)) |> PSet.of_seq |> ref in
while not (PSet.is_empty !pq) do
  let x, i = PSet.min_elt !pq in
  pq := PSet.remove (x, i) !pq;
  Printf.printf "%d\n%!" (i + 1);
  let y = Scanf.scanf " %s" (fun s -> s) in
  if not (String.equal y "DONE") then pq := PSet.add (int_of_string y, i) !pq
done;
print_endline "DONE"
