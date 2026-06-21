import bisect
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = [tuple(map(int, reversed(input().split()))) for _ in range(n)]
    a.sort()
    ss = []
    mx = a[-1][1]
    for k, v in reversed(a):
        mx = max(mx, v)
        ss.append((k, mx))
    ss.reverse()
    q = int(input())
    qs = [ss[bisect.bisect_left(ss, (x + 1, 0))][1] for x in map(int, input().split())]
    for x in qs:
        print(x)
main()
