module Deque = struct
  type node =
    { x : int
    ; mutable prev : node
    ; mutable next : node
    }

  type t =
    { head : node
    ; tail : node
    }

  let create () =
    let rec head = { x = 0; prev = head; next = tail }
    and tail = { x = 0; prev = head; next = tail } in
    { head; tail }
  ;;

  let is_empty { head; tail } = head.next == tail
  let peek_front { head; tail = _ } = head.next.x
  let peek_back { head = _; tail } = tail.prev.x

  let push_back x { head = _; tail } =
    let new_node = { x; prev = tail.prev; next = tail } in
    tail.prev.next <- new_node;
    tail.prev <- new_node
  ;;

  let pop_front { head; tail = _ } =
    head.next.next.prev <- head;
    head.next <- head.next.next
  ;;

  let pop_back { head = _; tail } =
    tail.prev.prev.next <- tail;
    tail.prev <- tail.prev.prev
  ;;
end

module MinQ = struct
  type t =
    { q : int Queue.t
    ; mns : Deque.t
    }

  let create () = { q = Queue.create (); mns = Deque.create () }
  let get_min { q = _; mns } = Deque.peek_front mns

  let push x { q; mns } =
    Queue.add x q;
    while (not (Deque.is_empty mns)) && Deque.peek_back mns > x do
      Deque.pop_back mns
    done;
    Deque.push_back x mns
  ;;

  let pop { q; mns } =
    let x = Queue.pop q in
    if Deque.peek_front mns = x then Deque.pop_front mns
  ;;
end

let read_int () = Scanf.scanf " %d" Fun.id;;

let n = read_int () in
let a = Array.init (n - 1) (fun _ -> read_int ()) in
let m = read_int () in
let b = Array.make (n - 1) (-1) in
for _ = 1 to m do
  let u = read_int () in
  let v = read_int () in
  b.(v - 2) <- Int.max b.(v - 2) (u - 1)
done;
let dp = MinQ.create () in
let lo = ref 0 in
let p = ref 0 in
for i = 0 to n - 2 do
  MinQ.push (!p + a.(i)) dp;
  if b.(i) <> -1
  then (
    while !lo < b.(i) do
      MinQ.pop dp;
      lo := !lo + 1
    done;
    p := MinQ.get_min dp)
done;
Printf.printf "%d\n" !p
