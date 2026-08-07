module IntMap = Map.Make (Int)
module IntSet = Set.Make (Int)

let read_int () = Scanf.scanf "%d " Fun.id;;

let n = read_int () in
let a = Array.init n (fun _ -> read_int ()) in
let ma = ref IntMap.empty in
let ss = Array.make (n + 1) IntMap.empty in
for i = n - 1 downto 0 do
  let temp =
    match IntMap.find_opt a.(i) !ma with
    | None -> ss.(i + 1)
    | Some j -> IntMap.remove j ss.(i + 1)
  in
  ss.(i) <- IntMap.add i a.(i) temp;
  ma := IntMap.add a.(i) i !ma
done;
for _ = 1 to read_int () do
  let i = read_int () - 1 in
  let m = read_int () in
  let s = ref IntSet.empty in
  for _ = 1 to m do
    s := IntSet.add (read_int ()) !s
  done;
  let r =
    IntMap.to_seq ss.(i)
    |> Seq.find (fun (_, v) -> not (IntSet.mem v !s))
    |> function
    | None -> n
    | Some (j, _) -> j
  in
  Printf.printf "%d\n" (r - i)
done
