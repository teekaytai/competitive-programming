a, b = map(int, input().split())
dp = [[False] * (b+1) for _ in range(a+1)]
for i in range(1, a+1):
    for j in range(1, b+1):
        dp[i][j] = any(dp[i][k]==dp[i][j-k]==0 for k in range(1, j)) or any(dp[k][j]==dp[i-k][j]==0 for k in range(1, i))
print('BA'[dp[a][b]])
