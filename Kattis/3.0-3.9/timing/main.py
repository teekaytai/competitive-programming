import sys

input = lambda: sys.stdin.readline().strip()

def matmul(A, B):
    ans = [[0.0] * len(B) for _ in range(len(A[0]))]
    for r, R in enumerate(A):
        for k, va in enumerate(R):
            if not va: continue
            for c, vb in enumerate(B[k]):
                ans[r][c] += va * vb
    return ans

def matpow(M, p):
    n = len(M)
    ans = [[0.0] * n for _ in range(n)]
    for i in range(n):
        ans[i][i] = 1.0
    while p:
        if p & 1:
            ans = matmul(ans, M)
        M = matmul(M, M)
        p >>= 1
    return ans

tcs = int(input())
for tc in range(tcs):
    n, m, t = map(int, input().split())
    *b, = [[int(x)] for x in input().split()]
    M = [[0.0] * n for _ in range(n)]
    A = [[0.0] * n for _ in range(n)]
    for i in range(n): M[i][i] = 1.0; A[i][i] = 1.0
    for _ in range(m):
        u, v, w = input().split()
        u = int(u)
        v = int(v)
        w = float(w)
        M[v][u] = w
        M[u][u] -= w
        A[v][u] = 1.0
        A[u][v] = 1.0
    print(min(x[0] for x in matmul(A, matmul(matpow(M, t), b))))
