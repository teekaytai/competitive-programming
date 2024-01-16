from collections import deque
from heapq import *
S, m = map(int, input().split())
q = [(-x, -x) for x in map(int, input().split())]
q2 = []
t = None
zs = deque()
e = int(input())
for i in range(1, e+1):
    if i % m == 0 and q2:
        mh = heappop(q2)
        if mh < -1:
            heappush(q, ((mh+1)//2, mh))

    c = input()
    if c.startswith('AP'):
        zs.append(int(c.split()[1]))
        if t is not None:
            heappush(q, t)
            t = None
    else:
        z = zs.popleft()
        while z:
            if not q: break
            h, mh = heappop(q)
            mn = min(-h, z)
            h += mn
            z -= mn
            if h == 0:
                heappush(q2, mh)
        if z:
            print('overrun')
            break
        if t is not None:
            heappush(q, t)
            t = None
        if h < 0:
            t = h, mh
else:
    print('success')
