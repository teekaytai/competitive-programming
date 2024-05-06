from itertools import permutations
for tc in range(1, int(input())+1):
    n, m = map(int, input().split())
    g = [set() for _ in range(n)]
    for _ in range(m):
        u, v = map(int, input().split())
        u -= 1; v -= 1
        g[u].add(v)
        g[v].add(u)
    s = 0
    for p in permutations(range(n-1)):
        s += all(p[i] not in g[p[i+1]] for i in range(n-2)) and p[0] not in g[n-1] and p[-1] not in g[n-1]
    print(f'Case #{tc}:', s//2%9901)
