String.fold_left (fun total c -> total + Bool.to_int (Char.equal c '1')) 0 (read_line ())
|> Printf.printf "%d\n"
