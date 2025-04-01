from collections import Counter

def modinv(x, mod):
    return x if x <= 1 else mod - mod // x * modinv(mod % x, mod) % mod
    # return pow(x, -1, mod)

def moddiv(a, b, mod):
    return a * modinv(b, mod) % mod

n, p, k = map(int, input().split())
c = Counter(x**3 % p for x in map(int, input().split()))
if k == 0:
    print(c[0] and n - 1)
    exit()
t = 0
for x, v in c.items():
    y = moddiv(k, x, p)
    if x == y: t += v * (v - 1)
    else: t += c[y] * v
print(t // 2)
