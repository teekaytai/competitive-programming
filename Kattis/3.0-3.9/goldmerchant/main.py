import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, m = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]
    g = [[] for _ in range(n)]
    for _ in range(m):
        u, v = [int(x) for x in input().split()]
        u -= 1; v -= 1
        g[u].append(v)
        g[v].append(u)
    seen = [0] * n
    ans = 0
    for s in range(n):
        if seen[s]: continue
        seen[s] = 1
        q = [s]
        for u in q:
            for v in g[u]:
                if seen[v]: continue
                seen[v] = 1
                q.append(v)
        x = sorted(a[i] for i in q)
        y = sorted(b[i] for i in q)
        ans += sum(xx * yy for xx, yy in zip(x, y))
    print(ans)

main()
