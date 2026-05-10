from itertools import pairwise
from collections import defaultdict
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    INF = 10 ** 18
    h, w = [int(x) for x in input().split()]
    n = int(input())
    d = defaultdict(list)
    for _ in range(n):
        r, c = [int(x) for x in input().split()]
        d[r].append(c)
    ls = []
    ms = []
    for a in d.values():
        a.sort()
        ls.append((a[-1] - 1) * 2)
        ms.append(2 * min(a[-1] - 1, w - a[0], min((x - 1 + w - y for x, y in pairwise(a)), default=INF)))
    k = len(ls)
    ans = sum(ls)
    t = sum(ms)
    ms.sort(reverse=True)
    for i in range(1, k, 2):
        t += 2 * (w - 1) - ms[i] - ms[i - 1]
        ans = min(ans, t)
    print(ans)

main()
