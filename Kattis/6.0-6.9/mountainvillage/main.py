from heapq import *
import sys

input = lambda: sys.stdin.readline().strip()

INF = 1000000000

H, W = map(int, input().split())
DIRS = [-W-1, 1, W+1, -1]
g = []
for _ in range(H):
    g.extend(map(int, input().split()))
    g.append(-1)
g.extend([-1] * W)
D = [INF] * (H * W + 1)
seen = [-1] * len(g)
for R in range(H):
    for C in range(W):
        Z = R*(W+1) + C
        V = g[Z]
        seen[Z] = Z
        mx = V
        pq = [(mx, Z)]
        i = 0
        while pq:
            v, z = heappop(pq)
            i += 1
            mx = max(mx, v)
            D[i] = min(D[i], mx - V)
            for dz in DIRS:
                z2 = z + dz
                v2 = g[z2]
                if v2 >= V and seen[z2] != Z:
                    seen[z2] = Z
                    heappush(pq, (v2, z2))
n = int(input())
for _ in range(n):
    print(D[int(input())])
