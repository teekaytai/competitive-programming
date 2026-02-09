def matmul(A, B, mod):
    return [[sum(v * B[r][c] % mod for r, v in enumerate(R)) % mod for c in range(len(B[0]))] for R in A]

def matpow(M, p, mod):
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

n = int(input())
a0, *a = map(int, input().split())
M = [[1] + [0] * n]
for i in range(n - 1):
    M.append([1 if i+2==j else 0 for j in range(n+1)])
M.append([a0, *a[::-1]])
X = [[1], *([int(x)] for x in input().split())]
q = int(input())
for _ in range(q):
    t, m = map(int, input().split())
    print(matmul(matpow(M, t, m), X, m)[1][0])
