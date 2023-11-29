MOD = 1000000007
n, a, b, c = map(int, input().split())
A, B, C = a, b, c
for _ in range(n - 1):
    A, B, C = a * (B + C), b * (A + C), c * (A + B)
    A, B, C = A % MOD, B % MOD, C % MOD
print((A + B + C) % MOD)
