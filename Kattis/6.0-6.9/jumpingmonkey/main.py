n, m = map(int, input().split())
while n:
    g = [0] * n
    for i in range(m):
        u, v = map(int, input().split())
        g[u] |= 1 << v
        g[v] |= 1 << u
    if m >= n:
        print('Impossible')
        input()
        n, m = map(int, input().split())
        continue
    start = (1 << n) - 1
    def bfs():
        pars = {start: -1}
        q = [start]
        while q:
            nq = []
            for curr in q:
                bs = curr
                while bs:
                    b = bs & -bs
                    mask = curr - b
                    nxt = 0
                    while mask:
                        v = mask & -mask
                        nxt |= g[v.bit_length() - 1]
                        mask -= v
                    if nxt not in pars:
                        pars[nxt] = curr, b.bit_length() - 1
                        nq.append(nxt)
                    if nxt == 0:
                        return pars
                    bs -= b
            q = nq
        return None
    ps = bfs()
    if ps is None:
        print('Impossible')
    else:
        path = []
        curr = 0
        while curr != start:
            curr, v = ps[curr]
            path.append(v)
        print(f'{len(path)}:', *path[::-1])

    input()
    n, m = map(int, input().split())
