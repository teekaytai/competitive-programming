from collections import deque
import sys

input = lambda: sys.stdin.readline().rstrip()

def main():
    n, m = map(int, input().split())
    if n == 0:
        return False
    DIRS = [-m-1, -1, 1, m+1]
    g = [-1] * (n * (m + 1))
    g.extend([0] * (m + 1))
    for z in range(m, n * (m + 1), m + 1): g[z] = 0
    for _ in range(int(input())):
        r, c = map(int, input().split())
        g[r * (m + 1) + c] = False
    for _ in range(int(input())):
        r, c, r2, c2, w = map(int, input().split())
        g[r * (m + 1) + c] = (r2 * (m + 1) + c2) * 100000 + w + 10000
    INF = 100000000
    ds = [INF] * ((n + 1) * (m + 1))
    ds[0] = 0
    q = deque([0])
    inq = [0] * ((n + 1) * (m + 1))
    inq[0] = 1
    t = (n - 1) * (m + 1) + m - 1
    cs = [0] * ((n + 1) * (m + 1))
    V = n * m
    while q:
        z = q.popleft()
        inq[z] = 0
        if z == t: continue
        d = ds[z]
        if g[z] != -1:
            x = g[z]
            z2, w = divmod(x, 100000)
            d2 = d + w - 10000
            if d2 >= ds[z2]: continue
            cs[z2] += 1
            if cs[z2] == V:
                print('Never')
                return True
            ds[z2] = d2
            if not inq[z2]:
                inq[z2] = 1
                q.append(z2)
        else:
            for dz in DIRS:
                z2 = z + dz
                if not g[z2]: continue
                d2 = d + 1
                if d2 >= ds[z2]: continue
                cs[z2] += 1
                if cs[z2] == V:
                    print('Never')
                    return True
                ds[z2] = d2
                if not inq[z2]:
                    inq[z2] = 1
                    q.append(z2)
    print(ds[t] if ds[t] != INF else 'Impossible')
    return True

while main(): pass
