from heapq import *
import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    h, n = map(int, input().split())
    pq = []
    for a, c in zip(map(int, input().split()), map(int, input().split())):
        pq.append((0, a, c))
    heapify(pq)
    t = 0
    while h > 0:
        t, a, c = heappop(pq)
        h -= a
        heappush(pq, (t+c, a, c))
    print(t+1)

tcs = int(input())
for tc in range(tcs):
    main()
