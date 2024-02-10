from functools import lru_cache
import sys
sys.setrecursionlimit(200000)
n = int(input())
*a, = map(int, input().split())
C = [-1] * n
D = {}
B = [True] * n
for i, x in enumerate(a):
    if x != -1: B[x] = False
    else: B[i] = False; D[i] = (n, -1)

@lru_cache(maxsize=None)
def dp(v):
    if a[v] == -1:
        return v, 0
    c, d = dp(a[v])
    return c, d+1

for i, b in enumerate(B):
    if b:
        c, d = dp(i)
        C[i] = c
        D[c] = min(D[c], (d, i))

q = int(input())
for v in map(int, input().split()):
    print(D[C[v]][1])
