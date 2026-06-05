module P = struct
  type t = int * int

  let compare = compare
end

module PSet = Set.Make (P);;

for _ = 1 to read_int () do
  ignore (read_int ());
  let a = String.split_on_char ' ' (read_line ()) in
  let ans, _, _, _, _, _ =
    List.fold_left
      (fun (t, s1, s2, n1, n2, id) x ->
         let x = int_of_string x in
         let p = x, id in
         let new_s1, new_s2 =
           match PSet.max_elt_opt s1, n1 = n2 with
           | None, _ -> PSet.add p s1, s2
           | Some m, true ->
             if m >= p
             then PSet.add p s1, s2
             else (
               let temp_s2 = PSet.add p s2 in
               let m2 = PSet.min_elt temp_s2 in
               PSet.add m2 s1, PSet.remove m2 temp_s2)
           | Some m, false ->
             if m <= p
             then s1, PSet.add p s2
             else (
               let temp_s1 = PSet.remove m s1 in
               PSet.add p temp_s1, PSet.add m s2)
         in
         let new_n1, new_n2 = if n1 = n2 then n1 + 1, n2 else n1, n2 + 1 in
         let med =
           if new_n1 = new_n2
           then (fst (PSet.max_elt new_s1) + fst (PSet.min_elt new_s2)) / 2
           else fst (PSet.max_elt new_s1)
         in
         Int.add t med, new_s1, new_s2, new_n1, new_n2, id + 1)
      (0, PSet.empty, PSet.empty, 0, 0, 0)
      a
  in
  Printf.printf "%d\n" ans
done
