from collections import deque
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    qs = [deque() for _ in range(n + 1)]
    *a, = map(int, input().split())
    dp = [0] * (n + 1)
    for i, x in enumerate(a):
        qs[x].append(i)
        if len(qs[x]) == x:
            dp[i + 1] = dp[qs[x].popleft()] + x
        dp[i + 1] = max(dp[i + 1], dp[i])
    print(dp[-1])

tcs = int(input())
for tc in range(tcs):
    main()
