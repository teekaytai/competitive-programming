from statistics import median
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    m = median(a)
    dp = [0] * (n + 1)
    for i, x in enumerate(a):
        mx = -1000000000
        ts = [0, 0, 0]
        for j in range(i, -1, -1):
            ts[(a[j] >= m) + (a[j] > m)] += 1
            if (i - j) % 2 == 0 and abs(ts[0] - ts[2]) < ts[1]:
                mx = max(mx, dp[j] + 1)
        dp[i + 1] = mx
    print(dp[-1])

tcs = int(input())
for tc in range(tcs):
    main()
