let s1, s2 = Scanf.scanf "%s %s" (fun s1 s2 -> s1, s2) in
let ans, _ =
  Seq.fold_left2
    (fun (acc, p) c1 c2 ->
       let d = Char.code c2 - Char.code c1 in
       if Bool.equal (d >= 0) (p >= 0)
       then acc + Int.max (Int.abs d - Int.abs p) 0, d
       else acc + Int.abs d, d)
    (0, 0)
    (String.to_seq s1)
    (String.to_seq s2)
in
Printf.printf "%d\n" ans
