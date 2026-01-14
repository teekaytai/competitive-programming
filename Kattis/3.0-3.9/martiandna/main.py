n, k, r = map(int, input().split())
*a, = map(int, input().split())
cs = [0] * k
for _ in range(r):
    b, v = map(int, input().split())
    cs[b] = v
lo = 0
mn = n + 1
for hi, x in enumerate(a):
    cs[x] -= 1
    if cs[x] == 0:
        r -= 1
    while r == 0:
        mn = min(mn, hi - lo + 1)
        y = a[lo]
        cs[y] += 1
        if cs[y] == 1:
            r += 1
        lo += 1
print('impossible' if mn > n else mn)
