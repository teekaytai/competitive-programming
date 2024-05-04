n, m, s, d = map(int, input().split())
*a, = map(int, input().split())
I = sorted(range(s), key=a.__getitem__)
res = [0] * s
while m > 0:
    if not I:
        print('impossible')
        break
    m -= a[I.pop()]
else:
    for i in I:
        m = min(n, d - a[i])
        res[i] = m
        n -= m
    if n: print('impossible')
    else: print(*res)
