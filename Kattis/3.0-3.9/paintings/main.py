from functools import cache
import sys

input = lambda: sys.stdin.readline().rstrip()

def main():
    n = int(input())
    a = input().split()
    ma = {s: i for i, s in enumerate(a)}
    bs = [[True] * (n + 1) for _ in range(n)]
    for _ in range(int(input())):
        s, t = input().split()
        u = ma[s]
        v = ma[t]
        bs[u][v] = False
        bs[v][u] = False
    @cache
    def f(s, p=-1):
        if not s:
            return 1
        t = 0
        m = s
        while m:
            b = m & -m
            m ^= b
            u = b.bit_length() - 1
            if bs[u][p]:
                t += f(s ^ b, u)
        return t
    p = list(range(n))
    c = 1
    while c < n:
        if c == 0:
            c += 1
        if bs[p[c - 1]][p[c]]:
            c += 1
            continue
        if c == n - 1:
            c -= 1
        else:
            p[c+1:] = p[-1:c:-1]
        while p[c] > p[c + 1]:
            c -= 1
        for i in range(n - 1, c, -1):
            if p[c] < p[i]:
                p[c], p[i] = p[i], p[c]
                break
        p[c+1:] = p[-1:c:-1]
    print(f((1 << n) - 1))
    print(*(a[i] for i in p))

tcs = int(input())
for tc in range(tcs):
    main()
