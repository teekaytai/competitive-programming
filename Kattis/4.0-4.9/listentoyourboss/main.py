n, q = map(int, input().split())
g = [[] for _ in range(n)]
for v in range(1, n):
    g[int(input()) - 1].append(v)
tin = [-1] * n
tout = [-1] * n
st = [0]
t = 0
while st:
    u = st[-1]
    if tin[u] == -1:
        tin[u] = t
        for v in g[u]: st.append(v)
    else:
        st.pop()
        tout[u] = t
    t += 1
for _ in range(q):
    u, v = map(int, input().split())
    u -= 1; v -= 1
    print(['Yes', 'No'][tin[v] < tin[u] < tout[v]])
