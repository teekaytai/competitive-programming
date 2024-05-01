t = int(input())
for _ in range(t):
    i, m, n = map(int, input().split())
    p = [m]
    while p[-1] <= n:
        p.append(p[-1] * m)
    p.pop()

    dp = [1] * (n + 1)
    next_dp = [1] * (n + 1)
    for c in p:
        for j in range(1, n + 1):
            next_dp[j] = dp[j]
            next_dp[j] += next_dp[j - c] if j >= c else 0
        dp, next_dp = next_dp, dp
    print(i, dp[-1])
