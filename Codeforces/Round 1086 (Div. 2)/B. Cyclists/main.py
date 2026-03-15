from collections import deque
from heapq import *
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, k, p, m = [int(x) for x in input().split()]
    p -= 1
    a = [int(x) for x in input().split()]
    t = 0
    if k == n:
        print(m // a[p])
        return
    if p < k:
        if a[p] > m:
            return 0
        m -= a[p]
        t += 1
        a.append(a.pop(p))
        p = len(a) - 1
    pq = a[:k]
    heapify(pq)
    q = deque(a[k:])
    p -= k
    while m > 0:
        x = heappop(pq)
        q.append(x)
        m -= x
        if p == 0:
            if m < q[0]:
                break
            m -= q[0]
            t += 1
            q.append(q.popleft())
            p = len(q) - 1
        heappush(pq, q.popleft())
        p -= 1
    print(t)

tcs = int(input())
for tc in range(tcs):
    main()
