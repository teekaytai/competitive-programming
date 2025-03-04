n = int(input())
ms = [0]
ss = [0] * (n + 1)
g = [[] for _ in range(n + 1)]
ind = [0] * (n + 1)
for i in range(1, n + 1):
    m, k, *a = map(int, input().split())
    ms.append(m)
    for j in range(k):
        g[i].append((a[2*j], a[2*j+1]))
        ind[a[2*j]] += 1
s = [i for i in range(1, n + 1) if ind[i] == 0]
for i in s: ss[i] = ms[i]
ans = []
for _ in range(n):
    u = s.pop()
    ss[u] = min(ss[u], ms[u])
    if ms[u] - ss[u] < 1e-4:
        ans.append(u)
    for v, w in g[u]:
        ss[v] += w * ss[u] / 100
        ind[v] -= 1
        if ind[v] == 0: s.append(v)
print(*sorted(ans))
