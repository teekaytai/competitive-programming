module SSet = Set.Make (String)
module SMap = Map.Make (String)

let rec f s =
  let x = read_line () in
  if String.equal x "" then s else f (SSet.add x s)
;;

let rec g m =
  match In_channel.input_line stdin with
  | None -> m
  | Some x ->
    let i1 = String.rindex x '_' in
    let i2 = String.rindex_from x (i1 - 1) '_' in
    let k = String.sub x 0 i2 in
    let m2 =
      SMap.update
        k
        (function
          | None -> Some [ x ]
          | Some l -> Some (x :: l))
        m
    in
    g m2
;;

let s = f SSet.empty in
let m = g SMap.empty in
let d1 =
  SMap.bindings m
  |> List.filter_map (fun (k, v) ->
    if SSet.mem k s then None else Some (List.sort String.compare v))
  |> List.concat
in
let d2 = SSet.filter (fun x -> not (SMap.mem x m)) s in
if d1 = [] && SSet.is_empty d2
then print_endline "No mismatches."
else (
  List.iter (fun x -> Printf.printf "F %s\n" x) d1;
  SSet.iter (fun x -> Printf.printf "I %s\n" x) d2)
