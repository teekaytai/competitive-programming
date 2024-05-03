from heapq import *
n, m, k = map(int, input().split())
pq = [input().rsplit(maxsplit=1) for _ in range(n)]
pq.append(['"Jane Eyre"', str(k)])
heapify(pq)
q = []
for _ in range(m):
    a,b = input().split(maxsplit=1)
    q.append((int(a), b))
q.sort(reverse=True)
t = 0
while True:
    while q and q[-1][0] <= t:
        heappush(pq, q.pop()[1].rsplit(maxsplit=1))
    s, v = heappop(pq)
    t += int(v)
    if s == '"Jane Eyre"': break
print(t)
