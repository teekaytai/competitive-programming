from collections import defaultdict
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

DIRS = [(0, 1), (1, 0), (0, -1), (-1, 0)]

def main():
    n, m = map(int, input().split())
    if n == m == 1:
        print(0)
        return
    g = []
    ws = defaultdict(list)
    for r in range(n):
        g.append(list(input()))
        for c in range(m):
            if g[r][c] not in '.#':
                ws[g[r][c]].append((r, c))
    seen = [[False] * m for _ in range(n)]
    q = [(0, 0)]
    seen[0][0] = True
    i = 0
    while q:
        i += 1
        q2 = []
        for r,c in q:
            for dr, dc in DIRS:
                r2 = r + dr
                c2 = c + dc
                if r2 < 0 or r2 >= n or c2 < 0 or c2 >= m or seen[r2][c2] or g[r2][c2] == '#':
                    continue
                seen[r2][c2] = True
                if r2 == n-1 and c2 == m-1:
                    print(i)
                    return
                q2.append((r2, c2))
            if g[r][c] != '.':
                for r2, c2 in ws[g[r][c]]:
                    g[r2][c2] = '.'
                    if seen[r2][c2]: continue
                    seen[r2][c2] = True
                    q2.append((r2, c2))
                    if r2 == n-1 and c2 == m-1:
                        print(i)
                        return
        q = q2
    print(-1)

main()
