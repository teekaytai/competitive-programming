for _ = 1 to read_int () do
  let s =
    read_line ()
    |> String.to_seq
    |> Seq.map (fun c -> if c == 'T' then 1 else 0)
    |> Array.of_seq
  in
  let n = Array.length s in
  let ans = ref (0, 0) in
  let k = ref 1 in
  while !k * (1 lsl !k) <= n do
    let a = Array.make (n - !k + 1) 0 in
    let x = ref 0 in
    let t = 1 lsl !k in
    let m = t - 1 in
    for i = 0 to !k - 2 do
      x := (!x * 2) + s.(i)
    done;
    for i = 0 to n - !k do
      x := ((!x * 2) + s.(i + !k - 1)) land m;
      a.(i) <- !x
    done;
    for i = 0 to !k - 1 do
      let bs = Array.make t false in
      let lo = ref i in
      let hi = ref i in
      let exception Found of int in
      try
        while !hi < Array.length a do
          while bs.(a.(!hi)) do
            bs.(a.(!lo)) <- false;
            lo := !lo + !k
          done;
          bs.(a.(!hi)) <- true;
          hi := !hi + !k;
          if !hi - !lo = !k * t then raise (Found !lo)
        done
      with
      | Found j -> ans := !k, if fst !ans = !k then min j (snd !ans) else j
    done;
    k := !k + 1
  done;
  Printf.printf "%d %d\n" (fst !ans) (snd !ans)
done
