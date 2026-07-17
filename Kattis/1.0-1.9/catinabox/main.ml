let h, w, l, v = Scanf.scanf "%d %d %d %d" (fun h w l v -> h, w, l, v) in
print_endline [| "TOO TIGHT"; "COZY"; "SO MUCH SPACE" |].(1 + Int.compare (h * w * l) v)
