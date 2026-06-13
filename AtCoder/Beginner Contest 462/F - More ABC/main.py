import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    INF = 400000
    s = input()
    n = len(s)
    k = int(input())
    dp = [[INF] * (n + 1) for _ in range(k + 1)]
    xs = [(s[i] != 'C') + (i < 1 or s[i - 1] != 'B') + (i < 2 or s[i - 2] != 'A') for i in range(n)]
    dp[0] = [0] * (n + 1)
    for i, c in enumerate(s):
        if i < 2:
            continue
        x = xs[i]
        if x == 0:
            for j in range(1, k + 1):
                dp[j][i + 1] = dp[j][i - 2]
        elif xs[i - 1] == 0 or xs[i - 2] == 0:
            for j in range(1, k + 1):
                dp[j][i + 1] = min(dp[j][i], dp[j][i - 2] + x)
        else:
            for j in range(1, k + 1):
                dp[j][i + 1] = min(dp[j][i], dp[j - 1][i - 2] + x)
    print(dp[-1][-1] if dp[-1][-1] < INF else -1)

tcs = int(input())
for tc in range(tcs):
    main()
