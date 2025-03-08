import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, m = map(int, input().split())
    g = [[] for _ in range(n)]
    for _ in range(m):
        u, v, w = map(int, input().split())
        u -= 1; v -= 1
        g[u].append((v, w))
        g[v].append((u, w))
    def dfs(u, p, x):
        if u == n - 1: return x
        mn = 100000000000000000000
        for v, w in g[u]:
            b = 1 << v
            if p & b: continue
            mn = min(mn, dfs(v, p | b, x ^ w))
        return mn
    print(dfs(0, 1, 0))

# tcs = int(input())
# for tc in range(tcs):
main()
