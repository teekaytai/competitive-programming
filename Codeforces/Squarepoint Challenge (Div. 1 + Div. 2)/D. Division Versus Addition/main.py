from itertools import accumulate
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, q = map(int, input().split())
    *a, = map(int, input().split())
    ps = list(accumulate((x.bit_length() - 1 + (x - (1 << (x.bit_length() - 1)) > 1) for x in a), initial=0))
    cs = list(accumulate((x == (1 << (x.bit_length() - 1)) + 1 for x in a), initial=0))
    for _ in range(q):
        l, r = map(int, input().split())
        l -= 1
        r -= 1
        print(ps[r + 1] - ps[l] + (cs[r + 1] - cs[l]) // 2)

tcs = int(input())
for tc in range(tcs):
    main()
