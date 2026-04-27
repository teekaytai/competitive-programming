from heapq import *
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, m = [int(x) for x in input().split()]
    a = [-int(x) for x in input().split()]
    pq1 = a[::2]
    pq2 = a[1::2]
    heapify(pq1)
    heapify(pq2)
    t1 = 0
    t2 = 0
    for x in map(int, input().split()):
        if x % 2 == 1:
            t1 += 1
        else:
            t2 += 1
    ans = -sum(a)
    def f(pq, t):
        x = 0
        if t:
            x += heappop(pq)
            t -= 1
        while t and pq and pq[0] < 0:
            x += heappop(pq)
            t -= 1
        return x
    ans += f(pq1, t1) + f(pq2, t2)
    print(ans)

tcs = int(input())
for tc in range(tcs):
    main()
