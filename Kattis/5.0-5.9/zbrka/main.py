n, k = map(int, input().split())
dp = [1] * (k+1)
dp2 = [0] * (k+1)
dp2[0] = 1
t = 1
for i in range(2, n+1):
    for j in range(1, min(k, t)+1): dp2[j] = (dp2[j-1] + dp[j] - (dp[j-i] if j>=i else 0)) % 1000000007
    for j in range(t, k+1): dp2[j] = dp2[t]
    dp, dp2 = dp2, dp
    t += i
print((dp[k] - dp[k-1]) % 1000000007)
