module StringMap = Map.Make (String);;

let a =
  In_channel.input_line stdin
  |> Option.get
  |> String.split_on_char ' '
  |> List.map int_of_string
  |> Array.of_list
in
let ma =
  In_channel.fold_lines
    (fun acc line ->
       let k, t, e, x =
         Scanf.sscanf line "%s %d:%d:%d:%d %s %d" (fun k mo d h m e x ->
           k, (mo, d, h, m), e = "exit", x)
       in
       StringMap.add_to_list k (t, e, x) acc)
    StringMap.empty
    stdin
in
StringMap.iter
  (fun k lst ->
     let lst = List.fast_sort compare lst in
     let s, _ =
       List.fold_left
         (fun (s, p) ((_, _, h, _), e, x) ->
            if not e
            then s, Some (h, x)
            else (
              match p with
              | None -> s, None
              | Some (ph, px) -> s + (Int.abs (x - px) * a.(ph)) + 100, None))
         (200, None)
         lst
     in
     if s > 200 then Printf.printf "%s $%d.%02d\n" k (s / 100) (s mod 100))
  ma
