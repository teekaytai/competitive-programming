import sys

input = lambda: sys.stdin.readline().strip()

MOD = 998244353

tcs = int(input())
for tc in range(tcs):
    n, k = map(int, input().split())
    dp = [[1] * k]
    for i in range(1, n+1):
        dp.append([sum(dp[i - (j+1)*(p+1)][p] for p in range(min(k-j, i//(j+1)))) % MOD for j in range(k)])
    print(sum(dp[-1]) % MOD)
