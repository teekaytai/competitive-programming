from collections import defaultdict
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    h, w, n = map(int, input().split())
    d1 = defaultdict(set)
    d2 = defaultdict(set)
    for _ in range(n):
        x, y = map(int, input().split())
        d1[x].add(y)
        d2[y].add(x)
    q = int(input())
    for _ in range(q):
        t, v = map(int, input().split())
        if t == 1:
            print(len(d1[v]))
            for y in d1[v]:
                d2[y].discard(v)
            del d1[v]
        else:
            print(len(d2[v]))
            for x in d2[v]:
                d1[x].discard(v)
            del d2[v]

# tcs = int(input())
# for tc in range(tcs):
main()
