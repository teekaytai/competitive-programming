import sys

input = lambda: sys.stdin.readline().strip()

def main():
    n, k, m = map(int, input().split())
    g = [[] for _ in range(n+1)]
    S = set()
    for _ in range(m):
        u, v = map(int, input().split())
        if u == k: S.add(v)
        elif v == k: S.add(u)
        else:
            g[u].append(v)
            g[v].append(u)
    seen = [0] * (n+1)
    for start in S:
        s = [(start, start)]
        seen[start] = 1
        while s:
            v, p = s.pop()
            for u in g[v]:
                if u == p or seen[u]: continue
                seen[u] = 1
                if u in S:
                    print('NO')
                    return
                s.append((u, v))
    print('YES')

main()
