let re = Str.regexp "<\\([^>]*\\)>" in
let r () =
  let s = read_line () in
  let rec loop i acc =
    try
      let j = Str.search_forward re s i in
      let tag = Str.matched_group 1 s in
      let i2 = j + String.length tag in
      loop i2 (if tag.[0] <> '/' then tag :: acc else acc)
    with
    | Not_found -> acc
  in
  loop 0 []
in
for _ = 1 to read_int () do
  let a = r () in
  let b = r () in
  let res =
    List.fold_left2
      (fun acc s t ->
         match acc with
         | None -> None
         | Some lst ->
           if s = t
           then acc
           else (
             let s2 = String.lowercase_ascii s in
             let t2 = String.lowercase_ascii t in
             if s2 <> t2
             then None
             else (
               let tagname =
                 match String.index_opt s2 ' ' with
                 | None -> s2
                 | Some i -> String.sub s2 0 i
               in
               Some (tagname :: lst))))
      (Some [])
      a
      b
  in
  match res with
  | None -> print_endline "different"
  | Some [] -> print_endline "identical"
  | Some lst ->
    print_string "similar";
    List.iter (Printf.printf " %s") lst;
    print_newline ()
done
