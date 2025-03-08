import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    h, w = map(int, input().split())
    W = 1 << w
    dp = [[0] * W for _ in range(w + 1)]
    for i in range(h):
        x = int(input(), 2)
        dp[0][x] += 1
    for i in range(w):
        for j in range(w - 1, -1, -1):
            for k in range(W):
                dp[j][k] = dp[j][k] + dp[j - 1][k ^ (1 << i)]
    ans = [0] * W
    for c, r in enumerate(dp):
        k = min(c, w - c)
        for i, x in enumerate(r): ans[i] += x * k
    print(min(ans))

# tcs = int(input())
# for tc in range(tcs):
main()
