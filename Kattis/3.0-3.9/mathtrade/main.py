n = int(input())
g = []
def f(key, mapping={}):
    if key not in mapping:
        mapping[key] = len(mapping)
        g.append([])
    return mapping[key]
for _ in range(n):
    _, a, b = input().split()
    g[f(a)].append(f(b))
def dfs(start, v, d=0, seen=[False]*len(g)):
    seen[v] = True
    mx = 0
    for u in g[v]:
        if u == start:
            mx = max(mx, d + 1)
        elif not seen[u]:
            mx = max(mx, dfs(start, u, d + 1))
    seen[v] = False
    return mx
print(max(dfs(v, v) for v in range(len(g))) or 'No trades possible')
