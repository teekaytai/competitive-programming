from heapq import *
n, m = map(int, input().split())
pq = []
x = n
A = []
for _ in range(n):
    a, s = map(int, input().split())
    A.append((a, s))
A.sort()
for a, s in A:
    while pq and pq[0] + m < a: heappop(pq)
    if not pq or pq[0] > a:
        x -= 1
        heappush(pq, a+s)
    else:
        heapreplace(pq, a+s)
print(x)
