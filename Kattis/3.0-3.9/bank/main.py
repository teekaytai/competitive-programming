from heapq import *
n, t = map(int, input().split())
a = []
for _ in range(n):
    x, y = map(int, input().split())
    a.append((y, x))
a.sort()
pq = []
s = 0
for i in range(t, -1, -1):
    while a and a[-1][0] >= i: heappush(pq, -a.pop()[1])
    if pq: s -= heappop(pq)
print(s)
