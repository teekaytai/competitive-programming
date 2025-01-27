from collections import deque
from heapq import *
d, n = map(int, input().split())
q = deque()
pq = []
c = 1
ans = []
for i in range(n):
    while q and q[0][0] <= i: heappush(pq, q.popleft()[1])
    t, *x = input().split()
    if t == 'a':
        if pq: ans.append(heappop(pq))
        else: ans.append(c); c += 1
    else:
        q.append((i + d, int(x[0])))
print('\n'.join(map(str, ans)))
