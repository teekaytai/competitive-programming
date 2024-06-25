import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

DIRS = [(-1, 0), (0, 1), (0, -1), (1, 0)]

def main():
    h, w = map(int, input().split())
    g = [[x=='#' for x in input()] for _ in range(h)]
    rs = [w - sum(row) for row in g]
    cs = [h - sum(col) for col in zip(*g)]
    d = [[rs[r] + cs[c] + g[r][c] - 1 for c in range(w)] for r in range(h)]
    ps = [[0] * w for _ in range(h)]
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
            mnr -= 1
            mxr += 1
            mnc -= 1
            mxc += 1
            # printerr(t, mnr, mxr, mnc, mxc)
            ps[max(mnr, 0)][0] += t
            if mxr+1 < h: ps[mxr+1][0] -= t
            ps[0][max(mnc, 0)] += t
            if mxc+1 < w: ps[0][mxc+1] -= t
            ps[max(mnr, 0)][max(mnc, 0)] -= t
            if mxr+1 < h: ps[mxr+1][max(mnc, 0)] += t
            if mxc+1 < w: ps[max(mnr, 0)][mxc+1] += t
            if mxr+1 < h and mxc+1 < w: ps[mxr+1][mxc+1] -= t
    m = 0
    thing = [0] * w
    for r, row in enumerate(d):
        t = 0
        for c, (x, y) in enumerate(zip(row, ps[r])):
            t += y
            thing[c] += t
            m = max(m, x + thing[c])
        # printerr(thing)
    print(m)

tcs = int(input())
for tc in range(tcs):
    main()
