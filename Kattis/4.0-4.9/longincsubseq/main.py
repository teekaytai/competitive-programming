*I, = open(0)
for l in I[1::2]:
    *a, = map(int, l.split())
    s = []
    p = []
    for i, x in enumerate(a):
        lo = 0; hi = len(s)
        while lo < hi:
            mid = (lo + hi) // 2
            if a[s[mid]] < x: lo = mid + 1
            else: hi = mid
        p.append(s[lo-1] if lo>0 else -1)
        s[lo:lo+1] = [i]
    curr = s[-1]
    r = []
    while curr != -1:
        r.append(curr)
        curr = p[curr]
    print(len(r))
    print(*r[::-1])
