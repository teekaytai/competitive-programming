import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

MOD = 998244353

def main():
    n = int(input())
    *a, = map(int, input().split())
    p, q = 0, 0
    r, s = 1, 1
    for x in a:
        if abs(p+x) == abs(q+x):
            p2 = abs(p+x)
            r2 = (r * (1 + (p+x>=0)) + s * (p != q) * (1 + (q+x>=0))) % MOD
        else:
            p2, r2 = max((abs(p+x), r * (1 + (p+x>=0)) % MOD), (abs(q+x), s * (1 + (q+x>=0)) % MOD))
        if p+x == q+x:
            q2 = p+x
            s2 = (r * (1 + (p+x>=0)) + s * (p != q) * (1 + (q+x>=0))) % MOD
        else:
            q2, s2 = min((p+x, r * (1 + (p+x>=0)) % MOD), (q+x, s * (1 + (q+x>=0)) % MOD))
        p, q, r, s = p2, q2, r2, s2
        # printerr(p, q, r, s)
    print(r)

tcs = int(input())
for tc in range(tcs):
    main()
