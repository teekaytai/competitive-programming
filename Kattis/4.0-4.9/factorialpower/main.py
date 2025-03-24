n, m = map(int, input().split())
def f(p, c):
    t = 0
    b = p
    while b <= m:
        t += m // b
        b *= p
    return t // c
mn = 1e16
i = 2
while n > 1:
    if i * i > n:
        mn = min(mn, f(n, 1))
        break
    c = 0
    while n % i == 0: c += 1; n //= i
    if c: mn = min(mn, f(i, c))
    i += 1
print(mn)
