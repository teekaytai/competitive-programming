for l in open(0):
    k, n = map(int, l.split())
    k += 1
    dp = [1/k] * k
    for _ in range(n-1):
        dp = [1/k*((i>0 and dp[i-1]) + dp[i] + (i<k-1 and dp[i+1])) for i in range(k)]
    print(sum(dp)*100)
