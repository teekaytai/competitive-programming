import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

DIRS = [(-1,0), (1, 0), (0,-1), (0,1)]
D = dict(zip('UDLR?', DIRS+[(0,0)]))

def main():
    n, m = map(int, input().split())
    g = [list(map(D.get,input())) for _ in range(n)]
    s = [
        *((-1, i) for i in range(m)),
        *((n, i) for i in range(m)),
        *((i, -1) for i in range(n)),
        *((i, m) for i in range(n)),
    ]
    seen = [[False]*m for _ in range(n)]
    while s:
        r, c = s.pop()
        for dr, dc in DIRS:
            r2=r+dr
            c2=c+dc
            if r2<0 or r2>=n or c2<0 or c2>=m or seen[r2][c2] or g[r2][c2]!=(-dr, -dc):
                continue
            seen[r2][c2] = True
            s.append((r2, c2))
    for r, row in enumerate(g):
        for c, t in enumerate(row):
            if t != (0, 0): continue
            for dr, dc in DIRS:
                r2=r+dr
                c2=c+dc
                if 0<=r2<n and 0<=c2<m and not seen[r2][c2]:
                    break
            else:
                seen[r][c] = True
    print(n*m-sum(sum(R) for R in seen))

tcs = int(input())
for tc in range(tcs):
    main()
