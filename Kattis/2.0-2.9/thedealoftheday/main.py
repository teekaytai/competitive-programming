*a, = map(int, input().split())
n = int(input())
dp = [1] + [0] * n
for x in a:
    for i in range(n, 0, -1):
        dp[i] += dp[i-1] * x
print(dp[n])
