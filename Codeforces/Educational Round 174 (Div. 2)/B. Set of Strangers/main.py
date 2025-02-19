import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

DIRS = [(-1, 0), (0, 1), (1, 0), (0, -1)]
def main():
    n, m = map(int, input().split())
    cs = [0] * (n*m + 1)
    g = [list(map(int, input().split())) for _ in range(n)]
    for i, row in enumerate(g):
        for j, x in enumerate(row):
            cs[x] = max(cs[x], 1 + any(0<=i+di<n and 0<=j+dj<m and g[i+di][j+dj]==x for di, dj in DIRS))
    t = 0
    mx = 0
    for c in cs:
        t += c
        mx = max(mx, c)
    print(t - mx)

tcs = int(input())
for tc in range(tcs):
    main()
