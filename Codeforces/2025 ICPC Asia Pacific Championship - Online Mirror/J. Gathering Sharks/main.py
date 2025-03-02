import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    *a, = map(int, input().split())
    dp = [[0] * n for _ in range(n)]
    I = sorted(range(n), key=a.__getitem__)
    for l in range(1, n):
        for i in range(n - l):
            j = i + l
            dp[j][i] = min(dp[j - 1][k] + dp[k][i] + abs(I[j] - I[k]) for k in range(i, i + l))
    print(dp[n - 1][0])

# tcs = int(input())
# for tc in range(tcs):
main()
