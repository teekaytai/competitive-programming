from operator import itemgetter
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

MOD = 998244353

def modsum(a, mod=MOD):
    t = 0
    for x in a:
        t = (t + x) % mod
    return t

def matmul(A, B, mod=MOD):
    ans = [[0] * len(B[0]) for _ in range(len(A))]
    for r, R in enumerate(A):
        for k, va in enumerate(R):
            if not va: continue
            for c, vb in enumerate(B[k]):
                ans[r][c] = (ans[r][c] + va * vb) % mod
    return ans

def matpow(M, p, mod=MOD):
    n = len(M)
    ans = [[0] * n for _ in range(n)]
    for i in range(n):
        ans[i][i] = 1
    while p:
        if p & 1:
            ans = matmul(ans, M, mod)
        M = matmul(M, M, mod)
        p >>= 1
    return ans

def main():
    n, k = [int(x) for x in input().split()]
    ps = {}
    ps[''] = 0
    ss = [input() for _ in range(k)]
    s = set(ss)
    for w in ss:
        for i in range(1, len(w)):
            p = w[:i]
            if any(p[-j:] for j in range(1, i + 1)) in s:
                break
            ps.setdefault(p, len(ps))
    m = len(ps)
    mat = [[0] * m for _ in range(m)]
    for p, u in ps.items():
        for c in 'abcdefghijklmnopqrstuvwxyz':
            p2 = p + c
            if any(p2[-i:] in s for i in range(1, len(p2) + 1)):
                continue
            while (v := ps.get(p2)) is None:
                p2 = p2[1:]
            mat[v][u] += 1
    b = [[0] for _ in range(m)]
    b[0][0] = 1
    print(modsum(map(itemgetter(0), matmul(matpow(mat, n), b))))

main()
