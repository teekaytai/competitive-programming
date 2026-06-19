let n, k = Scanf.sscanf (read_line ()) "%d %d" (fun n k -> n, k) in
let a =
  String.split_on_char ' ' (read_line ()) |> Array.of_list |> Array.map int_of_string
in
Array.fast_sort Int.compare a;
let ans = ref 0 in
let lo = ref 0 in
for hi = 0 to n - 1 do
  while a.(!lo) + k <= a.(hi) do
    lo := !lo + 1
  done;
  ans := Int.max !ans (hi - !lo + 1)
done;
Printf.printf "%d\n" !ans
