from operator import itemgetter
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = []
    for i in range(1, n + 1):
        x, y = map(int, input().split())
        a.append((x, y, i))
    a.sort()
    p = sorted(a[:n//2], key=itemgetter(1), reverse=True)
    q = sorted(a[n//2:], key=itemgetter(1))
    for (_, _, i), (_, _, j) in zip(p, q):
        print(i, j)

tcs = int(input())
for tc in range(tcs):
    main()
