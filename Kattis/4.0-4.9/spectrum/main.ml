let n, m = Scanf.sscanf (read_line ()) "%d %d" (fun n m -> n, m) in
let a =
  read_line () |> String.split_on_char ' ' |> List.map int_of_string |> Array.of_list
in
let dp = Array.make_matrix (n + 1) (m + 1) Float.infinity in
Array.fill dp.(0) 0 (m + 1) 0.0;
for i = 0 to n - 1 do
  let t = ref 0 in
  let c = ref 0 in
  for j = i downto 0 do
    t := !t + (a.(j) * (j + 1));
    c := !c + a.(j);
    let p = ref 0.0 in
    if !c > 0
    then (
      let mean = float_of_int !t /. float_of_int !c in
      for k = i downto j do
        p := !p +. (((mean -. float_of_int (k + 1)) ** 2.0) *. float_of_int a.(k))
      done);
    for k = 1 to m do
      dp.(i + 1).(k) <- Float.min dp.(i + 1).(k) (dp.(j).(k - 1) +. !p)
    done
  done
done;
Printf.printf "%.12f\n" dp.(n).(m)
