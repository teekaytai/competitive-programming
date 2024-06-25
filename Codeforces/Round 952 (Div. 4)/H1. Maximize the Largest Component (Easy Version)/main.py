import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

DIRS = [(-1, 0), (0, 1), (0, -1), (1, 0)]

def main():
    h, w = map(int, input().split())
    g = [[x=='#' for x in input()] for _ in range(h)]
    rs = [w - sum(row) for row in g]
    cs = [h - sum(col) for col in zip(*g)]
    for R, row in enumerate(g):
        for C, cell in enumerate(row):
            if not cell: continue
            t = 1
            mnr = mxr = R
            mnc = mxc = C
            g[R][C] = 0
            s = [(R, C)]
            while s:
                r, c = s.pop()
                for dr, dc in DIRS:
                    r2 = r+dr
                    c2 = c+dc
                    if 0<=r2<h and 0<=c2<w and g[r2][c2]:
                        g[r2][c2] = 0
                        t += 1
                        mnr = min(mnr, r2)
                        mxr = max(mxr, r2)
                        mnc = min(mnc, c2)
                        mxc = max(mxc, c2)
                        s.append((r2, c2))
            # printerr(R, C, mnr, mxr, mnc, mxc)
            for r in range(max(mnr-1, 0), min(mxr+2, h)): rs[r] += t
            for c in range(max(mnc-1, 0), min(mxc+2, w)): cs[c] += t
    # printerr(rs)
    # printerr(cs)
    print(max(max(rs), max(cs)))

tcs = int(input())
for tc in range(tcs):
    main()
