from bisect import *
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, q = map(int, input().split())
    *a, = map(int, input().split())
    qs = [tuple(map(int, input().split())) for _ in range(q)]
    I = sorted(range(q), key=qs.__getitem__)
    s = []
    qi = 0
    ans = [0] * q
    for i, x in enumerate(a, start=1):
        if not s or x > s[-1]: s.append(x)
        else: s[bisect_left(s, x)] = x
        while qi < q and i == qs[I[qi]][0]:
            v = qs[I[qi]][1]
            ans[I[qi]] = bisect_right(s, v)
            qi += 1
    for v in ans: print(v)

# tcs = int(input())
# for tc in range(tcs):
main()
