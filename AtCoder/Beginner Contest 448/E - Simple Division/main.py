import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

MOD = 10007

def modpow(b, p, mod=MOD):
    r = 1
    while p:
        if p & 1:
            r = (r * b) % mod
        b = (b * b) % mod
        p >>= 1
    return r

def P(b, p, mod=MOD):
    r = 0
    t = 10
    while p:
        if p & 1:
            r = (r * t + b) % mod
        b = (b * t + b) % mod
        t = (t * t) % mod
        p >>= 1
    return r

def modinv(x, mod=MOD):
    return x if x <= 1 else mod - mod // x * modinv(mod % x, mod) % mod
    # return pow(x, -1, mod)  # Works for non-prime mod and works for x > mod

def moddiv(a, b, mod=MOD):
    return a * modinv(b, mod) % mod

def main():
    k, m = map(int, input().split())
    x = 0
    M = m * MOD
    for _ in range(k):
        c, l = map(int, input().split())
        x = (x * modpow(10, l, M) + P(c, l, M)) % M
    print(x // m % MOD)

main()
