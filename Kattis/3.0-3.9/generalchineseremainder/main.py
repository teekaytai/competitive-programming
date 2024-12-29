from math import lcm, prod
import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

N = 100001
primes = []
isp = [True] * N
isp[:2] = [False, False]
for i in range(2, N):
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
    for r, m in zip(remainders, moduli):
        M_i = M // m
        N_i = modinv(M_i, m)
        ans = (ans + r * M_i % M * N_i) % M
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

def main():
    a, n, b, m = map(int, input().split())
    ans = general_crt([a, b], [n, m])
    if ans is not None:
        print(ans, lcm(n, m))
    else:
        print('no solution')

tcs = int(input())
for tc in range(tcs):
    main()
