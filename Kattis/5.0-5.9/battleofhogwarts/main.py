from collections import deque
from itertools import chain
import sys

input = lambda: sys.stdin.readline().rstrip()

while True:
    n, m = map(int, input().split())
    if not n: break
    DIRS = [-m-2, -m-1, -m, -1, 1, m, m+1, m+2]
    g = '@'.join(chain((input() for _ in range(n)), ['@' * (m+1)]))
    seen = [0] * ((n+1) * (m+1))
    q = deque()
    x = 0
    for z in chain(range(m - 1), range(m - 1, n * (m + 1), m + 1)):
        if g[z] == '@': continue
        seen[z] = 1
        if g[z] == '.': q.append(z)
        else:
            x += 1
            q.appendleft(z)
    d = 0
    while q:
        if x == 0:
            x = len(q)
            d += 1
        z = q.popleft()
        x -= 1
        r, c = divmod(z, m + 1)
        if c == 0 or r == n - 1:
            print(d)
            break
        for dz in DIRS:
            z2 = z + dz
            if not seen[z2] and g[z2] != '@':
                seen[z2] = 1
                if g[z2] == '#':
                    q.appendleft(z2)
                    x += 1
                else:
                    q.append(z2)
    else:
        print(-1)
