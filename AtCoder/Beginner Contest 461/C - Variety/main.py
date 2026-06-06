from heapq import nlargest
from collections import Counter, defaultdict
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, k, m = [int(x) for x in input().split()]
    c = Counter()
    d = defaultdict(int)
    for _ in range(n):
        x, y = [int(x) for x in input().split()]
        c[y] += 1
        d[x] = max(d[x], y)
    s = nlargest(m, d.values())
    for y in s:
        c[y] -= 1
    t = sum(s)
    if k > m:
        e = sorted(c.elements(), reverse=True)
        t += sum(e[:k-m])
    print(t)

main()
