module Node = struct
  type 'a t =
    { k : int
    ; v : 'a
    }

  type 'a pair =
    { winner : 'a t
    ; loser : 'a t
    }

  let compare t1 t2 =
    Printf.printf "? %d %d\n%!" t1.k t2.k;
    Int.equal (read_int ()) 1
  ;;

  let make_leaf k = { k; v = () }

  let pair_up t1 t2 =
    if compare t1 t2
    then { k = t2.k; v = { winner = t2; loser = t1 } }
    else { k = t1.k; v = { winner = t1; loser = t2 } }
  ;;
end

let jacobsthal n =
  let a = Array.make n 0 in
  let j1 = ref 0 in
  let j2 = ref 1 in
  let i = ref 0 in
  while !i < n do
    for j = min (!j2 - 1) (n - 1) downto !j1 do
      a.(!i) <- j;
      i := !i + 1
    done;
    let temp = !j2 in
    j2 := !j2 + (2 * !j1);
    j1 := temp
  done;
  a
;;

let binary_search_insert a n winner loser =
  let lo = ref 0 in
  let hi = ref n in
  (match winner with
   | None -> ()
   | Some node ->
     hi := !hi - 1;
     while a.(!hi) != node do
       hi := !hi - 1
     done);
  while !lo < !hi do
    let mid = (!lo + !hi) / 2 in
    if Node.compare a.(mid) loser then lo := mid + 1 else hi := mid
  done;
  for i = n - 1 downto !lo do
    a.(i + 1) <- a.(i)
  done;
  a.(!lo) <- loser
;;

let rec ford_johnson : type a. a Node.t array -> unit =
  fun arr ->
  let n = Array.length arr in
  if n > 1
  then (
    let h = n / 2 in
    let pairs = Array.init h (fun i -> Node.pair_up arr.(2 * i) arr.((2 * i) + 1)) in
    ford_johnson pairs;
    let i = ref 0 in
    while !i < h do
      arr.(!i) <- pairs.(!i).v.winner;
      i := !i + 1
    done;
    let schedule = jacobsthal h in
    Array.iter
      (fun j ->
         let { Node.winner; loser } = pairs.(j).v in
         binary_search_insert arr !i (Some winner) loser;
         i := !i + 1)
      schedule;
    if Int.equal (n mod 2) 1 then binary_search_insert arr (n - 1) None arr.(n - 1))
;;

let n = read_int () in
let a = Array.init n (fun i -> Node.make_leaf (i + 1)) in
for i = 0 to n - 1 do
  let j = Random.int (i + 1) in
  let temp = a.(i) in
  a.(i) <- a.(j);
  a.(j) <- temp
done;
ford_johnson a;
print_char '!';
Array.iter (fun { Node.k; _ } -> Printf.printf " %d" k) a;
print_newline ()
