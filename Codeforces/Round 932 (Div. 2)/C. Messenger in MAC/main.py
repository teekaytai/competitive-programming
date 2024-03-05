from heapq import *
import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    tcs = int(input())
    for tc in range(tcs):
        n, l = map(int, input().split())
        A = [tuple(map(int, input().split()))[::-1] for _ in range(n)]
        A.sort()
        best = 0
        for i, (b, _) in enumerate(A):
            t = 0
            pq = []
            for j in range(i, n):
                b2, a2 = A[j]
                t += a2
                heappush(pq, -a2)
                while pq and t + b2 - b > l:
                    t -= -heappop(pq)
                best = max(best, len(pq))
        print(best)

main()
