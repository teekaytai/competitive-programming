import sys

input = lambda: sys.stdin.readline().strip()

tcs = int(input())
for tc in range(tcs):
    s = input()
    n = len(s)
    dp = [[2]*n]
    for i in range(1, n):
        prev = dp[-1]
        row = []
        for l in range(n-i):
            mn = prev[l+1] + (1 if s[l] == s[l+1] else 3)
            for m in range(l+2, l+i+1):
                if s[l] == s[m]: mn = min(mn, 2+dp[m-l-2][l+1]+dp[l+i-m][m])
            row.append(mn)
        dp.append(row)
    print(1+dp[-1][0])
