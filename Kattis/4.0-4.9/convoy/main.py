from heapq import *
n, k = map(int, input().split())
pq = [(int(input()),) * 2 for _ in range(n)]
pq2 = []
heapify(pq)
while n > 0:
    if k and pq and (not pq2 or pq[0] < pq2[0]):
        T, t = heappop(pq)
        heappush(pq2, (T + 2*t, t))
        n -= 5
        k -= 1
    else:
        T, t = pq2[0]
        heapreplace(pq2, (T + 2*t, t))
        n -= 4
print(T)
