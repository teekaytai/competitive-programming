n,_,*a = map(int, open(0))
dp = [1] * (n+1)
for i in range(1, n+1):
    dp[i] = sum(dp[i-j] for j in a if i >= j)
print(dp[n])
