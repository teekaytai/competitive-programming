from heapq import *
import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n, k = map(int, input().split())
    t = 0
    pq = []
    for c in map(int, input().split()):
        if t >= c:
            t -= c
            heappush(pq, -c)
        elif pq and c < -pq[0]:
            t -= c
            t += -heapreplace(pq, -c)
        t += k
    print(len(pq))

tcs = int(input())
for tc in range(tcs):
    main()
