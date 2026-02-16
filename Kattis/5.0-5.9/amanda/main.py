def f():
    print('impossible')
    exit()

n, m = map(int, input().split())
g = [[] for _ in range(n)]
cs = [0] * n
for _ in range(m):
    u, v, w = map(int, input().split())
    u -= 1; v -= 1
    if w == 2:
        if cs[u] == -1 or cs[v] == -1: f()
        cs[u] = cs[v] = 1
    elif w == 0:
        if cs[u] == 1 or cs[v] == 1: f()
        cs[u] = cs[v] = -1
    else:
        g[u].append(v)
        g[v].append(u)
seen = [0] * n
for s in range(n):
    if seen[s] or cs[s] == 0: continue
    seen[s] = 1
    st = [s]
    while st:
        u = st.pop()
        for v in g[u]:
            if seen[v] or cs[v]:
                if cs[v] != -cs[u]: f()
                continue
            seen[v] = 1
            cs[v] = -cs[u]
            st.append(v)
ans = sum(c == 1 for c in cs)
for s in range(n):
    if seen[s]: continue
    i = 1
    seen[s] = i
    sz1 = 1
    sz2 = 0
    q = [s]
    while q:
        i += 1
        q2 = []
        for u in q:
            for v in g[u]:
                if seen[v]:
                    if seen[v] == seen[u]: f()
                    continue
                seen[v] = i
                q2.append(v)
        sz2 += len(q2)
        sz1, sz2 = sz2, sz1
        q = q2
    ans += min(sz1, sz2)
print(ans)
