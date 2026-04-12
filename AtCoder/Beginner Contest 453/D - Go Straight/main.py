import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

DIRS = [(-1, 0), (1, 0), (0, -1), (0, 1)]
DS = 'UDLR'

def main():
    h, w = [int(x) for x in input().split()]
    g = [input() + '#' for _ in range(h)]
    g.append('#' * (w + 1))
    s = -1, -1
    t = -1, -1
    for r, row in enumerate(g):
        c = row.find('S')
        if c != -1:
            s = r, c
        c = row.find('G')
        if c != -1:
            t = r, c
    ps = [-1] * (h * w * 4)
    ps[(s[0] * w + s[1]) * 4] = -2
    ps[(s[0] * w + s[1]) * 4 + 1] = -2
    ps[(s[0] * w + s[1]) * 4 + 2] = -2
    ps[(s[0] * w + s[1]) * 4 + 3] = -2
    st = [(s[0], s[1], 0)]
    while st:
        r, c, d = st.pop()
        u = (r * w + c) * 4 + d
        x = g[r][c]
        for d2, (dr, dc) in enumerate(DIRS):
            if x == 'o' and d2 != d or x == 'x' and d2 == d: continue
            r2 = r + dr
            c2 = c + dc
            if g[r2][c2] == '#': continue
            v = (r2 * w + c2) * 4 + d2
            if ps[v] != -1: continue
            ps[v] = u
            st.append((r2, c2, d2))
            if r2 == t[0] and c2 == t[1]:
                print('Yes')
                k = v
                ans = []
                while ps[k] != -2:
                    ans.append(DS[k % 4])
                    k = ps[k]
                print(''.join(reversed(ans)))
                return
    print('No')
    print()

main()
