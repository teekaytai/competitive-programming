let words =
  [ "attack"; "die"; "fever"; "hunger"; "happy"; "antidisestablishmentarianism" ]
;;

let rec f l res =
  match l with
  | [] -> res
  | c1 :: c2 :: tl -> f tl ((c1, c2) :: res)
  | _ -> invalid_arg ""
;;

let rec read n ls =
  if n = 0
  then ls |> List.rev |> Array.of_list
  else (
    let l = read_line () in
    read (n - 1) (f (String.to_seq l |> List.of_seq) ls))
;;

let n = read_int () in
let n2 = n * n in
let s = read n [] in
List.iter
  (fun w ->
     let m = String.length w in
     let v = (2 * n2) - m + 1 in
     let can =
       if v < 0
       then false
       else
         Seq.ints 0
         |> Seq.take (Int.min n2 v)
         |> Seq.exists (fun i ->
           String.to_seqi w
           |> Seq.for_all (fun (j, c) ->
             let c1, c2 = s.((i + j) mod n2) in
             (c = c1 || c = c2) && (j < n2 || c1 = c2 || c <> w.[j - n2])))
     in
     print_endline (if can then "Y" else "N"))
  words
