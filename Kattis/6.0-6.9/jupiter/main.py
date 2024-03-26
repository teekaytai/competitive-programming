from collections import deque
import sys

input = lambda: sys.stdin.readline().strip()

n, q, s = map(int, input().split())
*s2q, = map(int, input().split())
*szs, = map(int, input().split())
qs = [deque() for _ in range(q)]
ds = []
for i in range(n):
    d, *a = map(int, input().split())
    ds.append(d)
    for j, x in enumerate(a):
        qid = s2q[j] - 1
        qs[qid].append([i, x])
        szs[qid] -= x
    for j, qu in enumerate(qs):
        p = 0
        while szs[j] < 0:
            p = max(p, qu[0][0])
            while p < i and not ds[p]:
                p += 1
            if p >= i:
                print('impossible')
                exit()
            m = min(ds[p], qu[0][1], -szs[j])
            ds[p] -= m
            qu[0][1] -= m
            if qu[0][1] == 0:
                qu.popleft()
            szs[j] += m
for qu in qs:
    for i, x in qu:
        ds[i] -= x
for i in range(n-1):
    ds[i+1] += min(ds[i], 0)
print('im'*(ds[-1] < 0) + 'possible')
