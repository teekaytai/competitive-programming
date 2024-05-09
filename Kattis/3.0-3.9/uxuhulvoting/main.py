for _ in range(int(input())):
    n = int(input())
    a = [[*map(int, input().split())] for _ in range(n)]
    *dp, = range(8)
    for r in reversed(a):
        dp2 = []
        for i in range(8):
            dp2.append(min((r[dp[j]], dp[j]) for j in (i^1, i^2, i^4))[1])
        dp = dp2
    print(f'{dp[0]:03b}'.replace('0','N').replace('1','Y'))
