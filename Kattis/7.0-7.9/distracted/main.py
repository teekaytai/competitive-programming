from collections import defaultdict
n, m = map(int, input().split())
d = dict([input().split() for _ in range(n)])
g = defaultdict(list)
seen = set()
res = '0'
s = []
for _ in range(m):
    u, _, v = input().split()
    g[u].append(v)
    if d[u] == 'm' and d[v] != 'm':
        if d[v] == 'u':
            print('1')
            exit()
        s.append(v)
        seen.add(v)
    if d[u] != 'u' and d[v] != 'm':
        res = '?'
while s:
    u = s.pop()
    for v in g[u]:
        if d[v] == 'u':
            print('1')
            exit()
        if d[v] == '?' and v not in seen:
            seen.add(v)
            s.append(v)
print(res)
