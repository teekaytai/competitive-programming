let reverse_string s =
  let len = String.length s in
  String.init len (fun i -> s.[len - 1 - i])
;;

Seq.forever (fun () ->
  let n = read_int () in
  Array.init n (fun _ -> read_line ()))
|> Seq.take_while (fun lines -> Array.length lines > 0)
|> Seq.iteri (fun i lines ->
  if i > 0 then print_newline ();
  let m = Array.fold_left (fun mx line -> max mx (String.length line)) 0 lines in
  Seq.ints 0
  |> Seq.take m
  |> Seq.iter (fun j ->
    let col =
      Array.to_seq lines
      |> Seq.map (fun line ->
        if j >= String.length line
        then ' '
        else (
          match line.[j] with
          | '-' -> '|'
          | '|' -> '-'
          | _ as c -> c))
      |> Seq.drop_while (Char.equal ' ')
      |> String.of_seq
      |> reverse_string
    in
    print_endline col))
