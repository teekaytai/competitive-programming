import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

MOD = 998244353

def modinv(x, mod=MOD):
    return x if x <= 1 else mod - mod // x * modinv(mod % x, mod) % mod
    # return pow(x, -1, mod)  # Works for non-prime mod and works for x > mod

def moddiv(a, b, mod=MOD):
    return a * modinv(b, mod) % mod

def modsum(a, mod=MOD):
    t = 0
    for x in a:
        t = (t + x) % mod
    return t

def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    c = 0
    for i in range(2, n + 1):
        c = (-1 + moddiv(c * (i - 3) % MOD, i - 1)) % MOD
    s = modsum(map((2).__rpow__, a))
    ans = s + 2 * moddiv(c, n * (n - 1) % MOD) * (modsum(a) ** 2 % MOD - s) % MOD
    print(ans % MOD)

main()
