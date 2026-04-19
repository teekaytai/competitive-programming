from heapq import*
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, m, k = map(int, input().split())
    g = [[] for _ in range(n)]
    for _ in range(m):
        u, v, w = map(int, input().split())
        u -= 1
        v -= 1
        g[u].append((v, w))
        g[v].append((u, w))
    smallest_k = []
    INF = 10000000000000000
    ds = [INF] * n
    ds[0] = 0
    pq = [(0, 0)]
    while pq:
        d, u = heappop(pq)
        if d > ds[u]: continue
        if u == n-1: break
        for v, w in g[u]:
            d2 = d + w
            if d2 >= ds[v]: continue
            ds[v] = d2
            heappush(pq, (d2, v))
    st = [0]
    seen = [False] * n
    seen[0] = True
    while st:
        u = st.pop()
        for v, w in g[u]:
            if u < v:
                heappush(smallest_k, -w)
                if len(smallest_k) > k: heappop(smallest_k)
            if seen[v]: continue
            seen[v] = True
            st.append(v)
    print(min(ds[n-1], -sum(smallest_k)))

# tcs = int(input())
# for tc in range(tcs):
main()
