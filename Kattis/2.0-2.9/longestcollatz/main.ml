let memo = Hashtbl.create 2200000

let rec f x =
  match Hashtbl.find_opt memo x with
  | Some res -> res
  | None ->
    let res =
      match x with
      | 1 -> 0
      | x when x mod 2 = 0 -> f (x / 2) + 1
      | x -> f ((x * 3) + 1) + 1
    in
    Hashtbl.add memo x res;
    res
;;

let n = read_int () in
let ans =
  Seq.ints 1
  |> Seq.take (n - 1)
  |> Seq.fold_left (fun acc i -> max acc (f i, i)) (0, -1)
  |> snd
in
Printf.printf "%d\n" ans
