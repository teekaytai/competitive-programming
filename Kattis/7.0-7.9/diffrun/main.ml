module CharMap = Map.Make (Char)

module Term = struct
  type t = int CharMap.t

  let from_stdin () =
    let rec loop t =
      match Scanf.scanf "%0c" Fun.id with
      | '\n' | '+' | '-' -> t
      | x ->
        let p =
          match Scanf.scanf_opt "%c^%d" (fun _ p -> p) with
          | None -> 1
          | Some p -> p
        in
        let t' =
          if p = 0
          then t
          else
            CharMap.update
              x
              (function
                | None -> Some p
                | Some p2 -> Some (p + p2))
              t
        in
        loop t'
    in
    loop CharMap.empty
  ;;

  let to_string t =
    t
    |> CharMap.to_seq
    |> Seq.map (fun (x, p) ->
      if p > 1 then Printf.sprintf "%c^%d" x p else String.make 1 x)
    |> List.of_seq
    |> String.concat ""
  ;;

  let differentiate t x =
    match CharMap.find_opt x t with
    | None -> CharMap.empty, 0
    | Some 1 -> CharMap.remove x t, 1
    | Some p -> CharMap.add x (p - 1) t, p
  ;;

  let compare t1 t2 =
    let rec loop s1 s2 =
      match Seq.uncons s1, Seq.uncons s2 with
      | None, None -> 0
      | None, Some _ -> 1
      | Some _, None -> -1
      | Some ((x1, p1), s1'), Some ((x2, p2), s2') ->
        let cmp = Char.compare x1 x2 in
        if cmp <> 0
        then cmp
        else (
          let cmp = Int.compare p2 p1 in
          if cmp <> 0 then cmp else loop s1' s2')
    in
    loop (CharMap.to_seq t1) (CharMap.to_seq t2)
  ;;
end

module TermMap = Map.Make (Term);;

let rec loop acc first =
  match Scanf.scanf_opt "\n" () with
  | Some () -> acc
  | None ->
    let sgn =
      if first
      then (
        match Scanf.scanf_opt "-" () with
        | None -> 1
        | Some () -> -1)
      else (
        match Scanf.scanf "%c" Fun.id with
        | '+' -> 1
        | '-' -> -1
        | _ -> invalid_arg "")
    in
    let c =
      match Scanf.scanf_opt "%d" Fun.id with
      | None -> sgn
      | Some c -> sgn * c
    in
    let term = Term.from_stdin () in
    let acc' =
      if c = 0
      then acc
      else
        TermMap.update
          term
          (function
            | None -> Some c
            | Some c2 ->
              let c' = c + c2 in
              if c' = 0 then None else Some c')
          acc
    in
    loop acc' false
in
let poly = loop TermMap.empty true in
let x = Scanf.scanf "d/d%c" Fun.id in
let res =
  poly
  |> TermMap.to_seq
  |> Seq.filter_map (fun (term, c) ->
    match Term.differentiate term x with
    | _, 0 -> None
    | term', p ->
      let ts = Term.to_string term' in
      let c' = c * p in
      let cs =
        if ts = "" || Int.abs c' > 1
        then Printf.sprintf "%+d" c'
        else if c' = 1
        then "+"
        else "-"
      in
      Some (cs ^ ts))
  |> List.of_seq
in
let ans =
  match res with
  | [] -> "0"
  | s :: ss ->
    let s' = if s.[0] = '+' then String.sub s 1 (String.length s - 1) else s in
    String.concat "" (s' :: ss)
in
print_endline ans
