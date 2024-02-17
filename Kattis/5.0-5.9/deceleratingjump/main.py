import sys

input = lambda: sys.stdin.readline().strip()

n = int(input())
*a, = map(int, input().split())
INF = 10000000000

dp = [-INF]*n
dp[0] = a[0]
dp[-1] = a[0] + a[-1]
for s in range(n-2, 0, -1):
    for i in range(s, n):
        dp[i] = max(dp[i], a[i] + dp[i-s])

print(dp[-1])
