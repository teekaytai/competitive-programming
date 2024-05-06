*a, _ = open(0)
for l in a:
    _, *X = map(int, l.split())
    s = []
    p = []
    for i, x in enumerate(X):
        lo = 0
        hi = len(s)
        while lo < hi:
            mid = (lo + hi) // 2
            if X[s[mid]] < x:
                lo = mid + 1
            else:
                hi = mid
        s[lo:lo+1] = [i]
        p.append(s[lo-1] if lo else -1)
    c = s[-1]
    ans = []
    while c != -1:
        ans.append(X[c])
        c = p[c]
    print(len(ans), *ans[::-1])
