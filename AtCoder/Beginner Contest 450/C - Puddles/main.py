import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

DIRS = [(1, 0), (0, 1), (-1, 0), (0, -1)]

def main():
    n, m = [int(x) for x in input().split()]
    g = []
    for _ in range(n):
        g.append(input())
    seen = [[False] * m for _ in range(n)]
    ans = 0
    for R in range(n):
        for C in range(m):
            if seen[R][C] or g[R][C] != '.': continue
            st = [(R, C)]
            seen[R][C] = True
            bad = False
            while st:
                r, c = st.pop()
                for dr, dc in DIRS:
                    r2 = r + dr
                    c2 = c + dc
                    if r2 < 0 or r2 >= n or c2 < 0 or c2 >= m:
                        bad = True
                    elif g[r2][c2] == '.' and not seen[r2][c2]:
                        seen[r2][c2] = True
                        st.append((r2, c2))
            ans += not bad
    print(ans)

main()
