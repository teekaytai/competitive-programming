import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, m, l, s, t = [int(x) for x in input().split()]
    g = [[] for _ in range(n)]
    for _ in range(m):
        u, v, w = [int(x) for x in input().split()]
        u -= 1
        v -= 1
        g[u].append((v, w))
    q = [(0, 0)]
    for _ in range(l):
        q2 = []
        for u, d in q:
            for v, w in g[u]:
                q2.append((v, d + w))
        q = q2
    ans = {v + 1 for v, d in q if s <= d <= t}
    print(*sorted(ans))

main()
