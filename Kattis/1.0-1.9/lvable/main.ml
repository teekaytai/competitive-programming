ignore (read_int ());
let s = read_line () in
let ans =
  try
    ignore (Str.search_forward (Str.regexp_string "lv") s 0);
    0
  with
  | Not_found -> if String.contains s 'l' || String.contains s 'v' then 1 else 2
in
Printf.printf "%d\n" ans
