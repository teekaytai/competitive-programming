from math import gcd, prod
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

N = 100002
primes = []
isp = [True] * N
isp[:2] = [False, False]
for i in range(2, N):
    # if i * i > N: break
    if not isp[i]: continue
    primes.append(i)
    for j in range(i * 2, N, i):
        isp[j] = False

def modinv(x, mod):
    return pow(x, -1, mod)

# Moduli must be coprime
def crt(remainders, moduli):
    M = prod(moduli)
    ans = 0
    for a, m in zip(remainders, moduli):
        M_i = M // m
        N_i = modinv(M_i, m)
        ans = (ans + a * M_i % M * N_i) % M
    return ans

def general_crt(remainders, moduli):
    cs = {}
    for r, m in zip(remainders, moduli):
        fs = []
        for p in primes:
            if p * p > m: break
            i = 0
            while m % p == 0:
                m //= p
                i += 1
            if i: fs.append((p, p**i))
        if m > 1: fs.append((m, m))
        for p, b in fs:
            c = r % b, b
            if p not in cs: cs[p] = c
            else:
                if cs[p][1] < b: cs[p], c = c, cs[p]
                if cs[p][0] % c[1] != c[0]: return None
    return crt(*zip(*cs.values()))

def f(x, vx, n):
    g = gcd(vx, n)
    assert x % g == 0
    m = n // g
    return -x//g * modinv(vx // g, m) % m, m

def main():
    n, x, y, vx, vy = map(int, input().split())
    try:
        g = gcd(vx, vy)
        vx //= g
        vy //= g
        rx, mx = f(x, vx, n)
        ry, my = f(y, vy, n)
        t = general_crt([rx, ry], [mx, my])
        X = (x + vx * t) // n
        Y = (y + vy * t) // n
        print(X - 1 + Y - 1 + (X + Y) // 2 + abs(X - Y) // 2)
    except:
        print(-1)

tcs = int(input())
for tc in range(tcs):
    main()
