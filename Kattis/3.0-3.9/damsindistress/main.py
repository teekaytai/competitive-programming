n, w = map(int, input().split())
g = [[] for _ in range(n+1)]
X = []
X.append((0, 0))
for i in range(1, n+1):
    d, c, u = map(int, input().split())
    g[d].append(i)
    X.append((c, u))
s = [(0, w)]
mn = w
while s:
    i, x = s.pop()
    c, u = X[i]
    m = max(x - u, c - u)
    mn = min(mn, m)
    for j in g[i]:
        s.append((j, m))
print(mn)
