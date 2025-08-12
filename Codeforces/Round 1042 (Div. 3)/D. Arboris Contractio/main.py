import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    g = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = map(int, input().split())
        u -= 1; v -= 1
        g[u].append(v)
        g[v].append(u)
    s = sum(len(vs) == 1 for vs in g)
    mx = max((len(vs) == 1) + sum(len(g[v]) == 1 for v in vs) for vs in g)
    print(s - mx)

tcs = int(input())
for tc in range(tcs):
    main()
