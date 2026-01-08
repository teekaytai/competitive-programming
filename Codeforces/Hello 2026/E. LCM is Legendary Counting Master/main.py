from collections import Counter
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

ts = [[k for j in range(1, int(i ** 0.5) + 1) if i % j == 0 for k in (i // j * (j + 1), (i // j + 1) * j)[:1 + (j * j != i)]] for i in range(1, 3001)]
MOD = 998244353

def main():
    n, m = [int(x) for x in input().split()]
    a0, *a = [int(x) for x in input().split()]
    if a0 > 1:
        print(0)
        return
    dp = {1: 1}
    for x in a:
        dp2 = Counter()
        for p, c in dp.items():
            for q in ts[p - 1]:
                if 0 != x != q or q > m:
                    continue
                dp2[q] = (dp2[q] + c) % MOD
        dp = dp2
    print(sum(dp.values()) % MOD)

tcs = int(input())
for tc in range(tcs):
    main()
