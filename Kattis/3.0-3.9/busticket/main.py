s, p, m, n = map(int, input().split())
*a, = map(int, input().split())
dp = [0]
lo = 0
for i, x in enumerate(a):
    while a[lo] <= x - m:
        lo += 1
    dp.append(min(dp[-1] + s, dp[lo] + p))
print(dp[-1])
