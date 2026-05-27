Scanf.scanf "%c%c\n%c%c" (fun a b c d ->
  [ a; b; c; d ]
  |> List.mapi (fun i x ->
    if Char.equal x '-'
    then 0
    else (
      let v = Char.code x - Char.code '1' in
      [| 0; 1; 1; 2 |].(i lxor v)))
  |> List.fold_left ( + ) 0
  |> Printf.printf "%d\n")
