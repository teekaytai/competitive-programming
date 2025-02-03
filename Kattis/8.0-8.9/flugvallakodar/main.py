import sys

input = lambda: sys.stdin.readline().rstrip()

n = int(input())
U = [(1 << (26 * 26)) - 1] * 26
ans = []
for _ in range(n):
    a = [ord(c) - 65 for c in input().upper()]
    l = len(a)
    ss = [0] * (l + 1)
    ps = [0] * (l + 1)
    for i in range(l - 1, -1, -1):
        c = a[i]
        ps[i] = ps[i + 1] | (ss[i + 1] << (26 * c))
        ss[i] = ss[i + 1] | (1 << c)
    for x, cx in enumerate(a):
        if U[cx] & ps[x + 1]: break
    else:
        ans.append(':(')
        continue
    for y in range(x + 1, l):
        cy = a[y]
        if (t := (U[cx] >> (26 * cy)) & ss[y + 1]): break
    for z in range(y + 1, l):
        cz = a[z]
        if (1 << cz) & t: break
    U[cx] ^= 1 << (26 * cy + cz)
    ans.append(''.join(chr(65 + c) for c in (cx, cy, cz)))
print(*ans, sep='\n')
