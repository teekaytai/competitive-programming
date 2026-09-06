let n = read_int () in
let a =
  if n = 4
  then [| 1, 2; 1, 3; 1, 4; 2, 3; 2, 4; 3, 4 |]
  else (
    let b = [| 1, 2; 1, 3; 2, 3; 4, 5; 4, 6; 5, 6 |] in
    Array.init ((n / 2) + 3) (fun i -> if i < 6 then b.(i) else (2 * i) - 5, (2 * i) - 4))
in
let exception Done in
try
  Array.iter
    (fun (x, y) ->
       Printf.printf "%d %d\n%!" x y;
       if read_line () = "Ljos!" then raise Done)
    a
with
| Done -> ()
