import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    g = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = [int(x) for x in input().split()]
        u -= 1; v -= 1
        g[u].append(v)
        g[v].append(u)
    seen = [False] * n
    seen[0] = True
    mx = 1
    q = [0]
    while q:
        q2 = []
        p = 0
        for u in q:
            b = 0
            for v in g[u]:
                if seen[v]:
                    continue
                b = 1
                seen[v] = True
                q2.append(v)
            p += b
        mx = max(mx, len(q2) + (p == 1))
        q = q2
    print(mx)

tcs = int(input())
for tc in range(tcs):
    main()
