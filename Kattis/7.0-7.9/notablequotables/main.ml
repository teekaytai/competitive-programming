let s = In_channel.input_all stdin in
let n = String.length s in
let o = "\"'!@#$%^&*abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" in
let seen = Array.make 128 false in
let i = ref 0 in
while !i < n do
  let b =
    match s.[!i] with
    | '"' | '\'' -> true
    | 'Q' ->
      if !i < n - 3 && s.[!i + 1] = '='
      then (
        i := !i + 2;
        true)
      else false
    | _ -> false
  in
  if not b
  then (
    print_char s.[!i];
    i := !i + 1)
  else (
    let d = s.[!i] in
    i := !i + 1;
    let j = ref !i in
    while s.[!j] <> d do
      if s.[!j] = '\\' then j := !j + 1;
      seen.(Char.code s.[!j]) <- true;
      j := !j + 1
    done;
    let k = ref 0 in
    while seen.(Char.code o.[!k]) do
      k := !k + 1
    done;
    let d' = o.[!k] in
    if d' <> '"' && d' <> '\'' then print_string "Q=";
    print_char d';
    while !i < !j do
      if s.[!i] = '\\' && s.[!i + 1] = d then i := !i + 1;
      let c = s.[!i] in
      seen.(Char.code c) <- false;
      print_char c;
      i := !i + 1
    done;
    print_char d';
    i := !i + 1)
done
