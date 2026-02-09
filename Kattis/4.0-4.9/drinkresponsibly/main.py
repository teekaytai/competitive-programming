def f(s):
    return int(s.replace('.', ''))

m, t, n = map(f, input().split())
t *= 6
ws = []
ds = []
cs = []
for _ in range(n):
    w, x, y, c = input().split()
    ws.append(w)
    ds.append((int(x) * 60 // int(y[2]), f(c)))

dp = [[-2] * (m + 1) for _ in range(t + 1)]
dp[0][0] = -1
for i in range(t + 1):
    for j in range(m + 1):
        for k, (v, c) in enumerate(ds):
            i2 = i - v
            j2 = j - c
            if i2 >= 0 and j2 >= 0 and dp[i2][j2] != -2:
                dp[i][j] = k
                break
if dp[-1][-1] == -2:
    print('IMPOSSIBLE')
else:
    ns = [0] * n
    i = t
    j = m
    while i > 0 or j > 0:
        k = dp[i][j]
        ns[k] += 1
        v, c = ds[k]
        i -= v
        j -= c
    for k, x in enumerate(ns):
        if x:
            print(ws[k], x)
