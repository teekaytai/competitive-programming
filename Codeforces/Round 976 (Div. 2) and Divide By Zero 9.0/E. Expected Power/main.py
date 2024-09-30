import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

MOD = 1000000007

def modinv(x, mod=MOD):
    return pow(x, -1, mod)
    # return x if x <= 1 else mod - mod // x * modinv(mod % x, mod) % mod

def moddiv(a, b, mod=MOD):
    return a * modinv(b, mod) % mod

def main():
    n = int(input())
    *A, = map(int, input().split())
    *P, = map(int, input().split())
    Q = [0] * 1024
    for a, p in zip(A, P):
        p = moddiv(p, 10000)
        Q[a] = (Q[a] * (1 - p) + (1 - Q[a]) * p) % MOD
    R1 = [0] * 1024
    R1[0] = 1
    for i, q in enumerate(Q):
        if q == 0: continue
        R2 = [0] * 1024
        for j in range(1024):
            k = i ^ j
            R2[j] = (R2[j] + (1-q) * R1[j]) % MOD
            R2[k] = (R2[k] + q * R1[j]) % MOD
        R1 = R2
    t = 0
    for i, p in enumerate(R1):
        t = (t + i*i*p) % MOD
    print(t)

tcs = int(input())
for tc in range(tcs):
    main()
