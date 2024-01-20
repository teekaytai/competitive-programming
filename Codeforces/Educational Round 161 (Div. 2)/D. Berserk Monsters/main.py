import sys

input = lambda: sys.stdin.readline().strip()

tcs = int(input())
for tc in range(tcs):
    n = int(input())
    *a, = map(int, input().split())
    *d, = map(int, input().split())
    a.append(0)
    prev = [*range(-1, n-1)]
    nxt = [*range(1, n+1)]
    nxt[-1]=-1
    *q, = range(n)
    res = []
    dead = [False] * n
    while q:
        deads = []
        for i in q:
            if a[prev[i]] + a[nxt[i]] > d[i]:
                deads.append(i)
                dead[i] = True
        q = []
        for i in deads:
            if prev[i] >= 0:
                nxt[prev[i]] = nxt[i]
                if not dead[prev[i]] and not (q and q[-1] == prev[i]): q.append(prev[i])
            if nxt[i] >= 0:
                prev[nxt[i]] = prev[i]
                if not dead[nxt[i]]: q.append(nxt[i])
        res.append(len(deads))

    print(*(res + [0] * (n-len(res))))
