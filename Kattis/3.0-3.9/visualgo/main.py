import heapq

n, m = map(int, input().split())
adj = [[] for _ in range(n)]
for _ in range(m):
    u, v, w = map(int, input().split())
    adj[u].append((v, w))
s, t = map(int, input().split())

q = [(0, s)]
seen = [False] * n
counts = [0] * n
counts[s] = 1
dists = [float('inf')] * n
dists[s] = 0
while q:
    d, u = heapq.heappop(q)
    if seen[u]:
        continue
    seen[u] = True
    if u == t:
        break
    for v, w in adj[u]:
        d2 = d + w
        if not seen[v] and d2 <= dists[v]:
            if d2 < dists[v]:
                heapq.heappush(q, (d2, v))
                dists[v] = d2
                counts[v] = counts[u]
            else:
                counts[v] += counts[u]
print(counts[t])
