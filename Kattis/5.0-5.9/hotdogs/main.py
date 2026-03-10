from collections import deque

def d1(p):
    return p[0] - p[1]

def d2(p):
    return p[0] + p[1]

def f(c, p):
    c[0] = min(c[0], p, key=d1)
    c[1] = max(c[1], p, key=d1)
    c[2] = min(c[2], p, key=d2)
    c[3] = max(c[3], p, key=d2)

def g(c1, c2):
    c1[0] = min(c1[0], c2[0], key=d1)
    c1[1] = max(c1[1], c2[1], key=d1)
    c1[2] = min(c1[2], c2[2], key=d2)
    c1[3] = max(c1[3], c2[3], key=d2)

DIRS = [(1, 0), (0, 1), (-1, 0), (0, -1)]

for _ in range(int(input())):
    n, w, h = map(int, input().split())
    if n == 0:
        print(h + w - 2)
        continue
    seen = [[False] * w for _ in range(h)]
    q = deque()
    for _ in range(n):
        x, y = map(int, input().split())
        q.append((x, y))
        seen[y][x] = True
    INF = 10000000
    ID = [(INF, 0), (0, INF), (INF, INF), (-1, -1)]
    cs = []
    while q:
        c = ID[:]
        for _ in range(len(q)):
            x, y = q.popleft()
            for dx, dy in DIRS:
                x2 = x + dx
                y2 = y + dy
                if 0 <= x2 < w and 0 <= y2 < h and not seen[y2][x2]:
                    seen[y2][x2] = True
                    f(c, (x2, y2))
                    q.append((x2, y2))
        cs.append(c)
    cs.pop()
    curr = ID
    i = len(cs)
    ans = 0
    for c in reversed(cs):
        g(curr, c)
        ans = max(ans, min(i, max(d1(c[1]) - d1(c[0]), d2(c[3]) - d2(c[2]))))
        i -= 1
    print(ans)
