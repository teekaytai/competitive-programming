from math import gcd
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

MOD = 998244353

def main():
    n, m = [int(x) for x in input().split()]
    ans = 0
    c10 = 10
    t9 = 9
    while n >= c10 - 1:
        g = gcd(c10 - 1, m)
        ans = (ans + n // (m // g) * t9) % MOD
        c10 *= 10
        t9 *= 10
    g = gcd(c10 - 1, m)
    ans = (ans + n // (m // g) * (n - c10 // 10 + 1)) % MOD
    print(ans)

tcs = int(input())
for tc in range(tcs):
    main()
