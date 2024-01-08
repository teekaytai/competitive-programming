import heapq

n, m = map(int, input().split())
adj = [[] for _ in range(n)]
for _ in range(m):
    u, v, w = map(int, input().split())
    u-=1
    v-=1
    adj[u].append((v, w))
    adj[v].append((u, w))

q = [(0, 0)]
seen = [False] * n
while q:
    d, u = heapq.heappop(q)
    if seen[u]:
        continue
    seen[u] = True
    if u == n - 1:
        print(d)
        break
    for v, w in adj[u]:
        d2 = d + w
        if not seen[v]:
            heapq.heappush(q, (d2, v))
