from math import gcd
import sys

input = lambda: sys.stdin.readline().strip()

MOD = 1000000007

def inv(x):
    return x if x <= 1 else MOD - MOD // x * inv(MOD % x) % MOD

tcs = int(input())
for tc in range(tcs):
    n, m, k = map(int, input().split())
    s = 0
    for _ in range(m):
        _, _, f = map(int, input().split())
        s = (s + f) % MOD
    s = s * k % MOD
    p = m % MOD
    t = p * ((k - 1) * k // 2) % MOD
    P = (s * n * (n-1) // 2 + t) % MOD
    Q = (n * (n-1) // 2) ** 2 % MOD
    g = gcd(P, Q)
    P //= g
    Q //= g
    print(P * inv(Q) % MOD)
