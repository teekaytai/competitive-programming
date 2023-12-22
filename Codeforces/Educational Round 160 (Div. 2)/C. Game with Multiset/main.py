c=[0] * 30
for _ in range(int(input())):
    t, n = map(int, input().split())
    if t == 1:
        c[n] += 1
    else:
        b = 1 << 29
        i=29
        while n and i >= 0:
            q = n // b
            q = min(q, c[i])
            n -= q * b
            b >>= 1
            i -= 1
        print('YES' if n == 0 else'NO')
