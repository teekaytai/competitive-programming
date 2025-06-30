from collections import Counter
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

MOD = 998244353

def modinv(x, mod=MOD):
    return x if x <= 1 else mod - mod // x * modinv(mod % x, mod) % mod

def moddiv(a, b, mod=MOD):
    return a * modinv(b, mod) % mod

def main():
    n, k = map(int, input().split())
    k -= 1
    *a, = map(int, input().split())
    t = sum(a)
    a[k] += 1
    c = Counter(a)
    b = sorted(c.items(), reverse=True)
    szs = [s * v for s, v in b]
    dp = []
    for i, (s, v) in enumerate(b):
        p = moddiv(s - 1, t)
        su = moddiv(s - 1, t)
        for j in range(i):
            p2 = moddiv(szs[j], t)
            p = (p + p2) % MOD
            su = (su + (1 + dp[j]) * p2) % MOD
        dp.append(moddiv(su + 1 - p, p))
        if a[k] == s:
            print(dp[i])
            return
    assert False

main()
