from collections import deque
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, k = map(int, input().split())
    g = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = map(int, input().split())
        u -= 1; v -= 1
        g[u].append(v)
        g[v].append(u)
    seen = [[-1] * k for _ in range(n)]
    seen[0][0] = -2
    ds = [-1] * n
    ds[0] = 0
    q = deque([(0, -1)])
    t = 0
    i = 0
    while q:
        i2 = (i + 1) % k
        for _ in range(len(q)):
            u, p = q.popleft()
            if i == 0 and ds[u] == -1:
                ds[u] = t
            for v in g[u]:
                if (v != p or i == 0) and seen[v][i2] != -2 and seen[v][i2] != u:
                    seen[v][i2] = u if seen[v][i2] == -1 else -2
                    q.append((v, u))
        i = i2
        t += i == 0
    print(*ds[1:])

tcs = int(input())
for tc in range(tcs):
    main()
