DIRS = [(0, -1), (0, 1), (-1, 0), (1, 0)]
h, w, n = map(int, input().split())
seen = [[False] * w for _ in range(h)]
q = []
for _ in range(n):
    r, c = map(int, input().split())
    r -= 1; c -= 1
    if not seen[r][c]:
        seen[r][c] = True
        q.append((r, c))
i = 0
while q:
    nq = []
    for r, c in q:
        for dr, dc in DIRS:
            r2 = r + dr
            c2 = c + dc
            if 0<=r2<h and 0<=c2<w and not seen[r2][c2]:
                seen[r2][c2] = True
                nq.append((r2, c2))
    q = nq
    i += 1
print(i)
