from itertools import pairwise
from heapq import *
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

class Node:
    def __init__(self, s, a, j=0) -> None:
        self.s = s
        self.a = a
        self.j = j

    def __lt__(self, other):
        return self.s > other.s

    def nxts(self, diffs):
        for i in range(self.j, len(diffs)):
            if not self.a[i]:
                continue
            d = diffs[i]
            a2 = self.a[:]
            a2[i + 1] += 1
            a2[i] -= 1
            yield Node(self.s - d, a2, i)

def main():
    n, k, q = [int(x) for x in input().split()]
    a = sorted((int(x) for x in input().split()), reverse=True)
    diffs = [y - x for y, x in pairwise(a)]
    pq = [Node(a[0] * k, [k] + [0] * (n - 1))]
    for _ in range(q):
        c = heappop(pq)
        print(c.s)
        for nxt in c.nxts(diffs):
            heappush(pq, nxt)

main()
