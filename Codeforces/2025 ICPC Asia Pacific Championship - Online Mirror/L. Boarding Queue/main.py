import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    DIRS = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    h, w, n, p = map(int, input().split())
    g = [list(map(int, input().split())) for _ in range(h)]
    can = [False] * (n + 1)
    for r in range(h):
        for c in range(w):
            if not g[r][c] or g[r][c] > p: continue
            for dr, dc in DIRS:
                r2 = r + dr
                c2 = c + dc
                if r2 < 0 or r2 >= h or c2 < 0 or c2 >= w or not g[r2][c2]: continue
                x = p + g[r2][c2] - g[r][c]
                if x != p and 1 <= x <= n: can[x] = True
    v = sum(can)
    print(v, '/', (n - 1), sep='')

# tcs = int(input())
# for tc in range(tcs):
main()
