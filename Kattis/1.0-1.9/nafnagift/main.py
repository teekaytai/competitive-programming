a = input()
b = input()
dp = [[(i, 1) for i in range(len(a) + 1)]]
dp[0][0] = (0, 0)
for j, y in enumerate(b):
    r = [(j + 1, 2)]
    for i, x in enumerate(a):
        if x == y: r.append((dp[j][i][0] + 1, 3))
        else: r.append(min((r[i][0] + 1, 1), (dp[j][i + 1][0] + 1, 2)))
    dp.append(r)
n = len(a)
m = len(b)
ans = []
while n or m:
    v = dp[m][n][1]
    ans.append(a[n - 1] if v & 1 else b[m - 1])
    n -= v & 1
    m -= v & 2 > 0
print(''.join(ans[::-1]))
