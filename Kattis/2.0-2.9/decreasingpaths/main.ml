let dirs = [| -1, -1; -1, 0; -1, 1; 0, -1; 0, 1; 1, -1; 1, 0; 1, 1 |];;

let h, w = Scanf.sscanf (read_line ()) "%d %d" (fun h w -> h, w) in
let g =
  Array.init h (fun _ ->
    read_line () |> String.split_on_char ' ' |> List.map int_of_string |> Array.of_list)
in
let a = Array.init (h * w) (fun i -> i / w, i mod w) in
Array.fast_sort (fun (r1, c1) (r2, c2) -> g.(r1).(c1) - g.(r2).(c2)) a;
let dp = Array.make_matrix h w 0 in
Array.iter
  (fun (r, c) ->
     let x = g.(r).(c) in
     let mx =
       Array.fold_left
         (fun acc (dr, dc) ->
            let r2 = r + dr in
            let c2 = c + dc in
            if r2 < 0 || r2 >= h || c2 < 0 || c2 >= w || g.(r2).(c2) >= x
            then acc
            else Int.max acc dp.(r2).(c2))
         0
         dirs
     in
     dp.(r).(c) <- mx + 1)
  a;
let ans =
  Array.fold_left (fun acc row -> Int.max acc (Array.fold_left Int.max 0 row)) 0 dp
in
Printf.printf "%d\n" ans
