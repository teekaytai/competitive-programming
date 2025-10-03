from itertools import accumulate
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, q = map(int, input().split())
    *a, = map(int, input().split())
    ps = list(accumulate(a, initial=0))
    cs = list(accumulate((a[i] == a[i + 1] for i in range(n - 1)), initial=0))
    for _ in range(q):
        l, r = map(int, input().split())
        l -= 1
        r -= 1
        d = r - l + 1
        if d % 3 or (ps[r + 1] - ps[l]) % 3:
            print(-1)
            continue
        if cs[r] - cs[l]:
            print(d // 3)
        else:
            print(d // 3 + 1)

tcs = int(input())
for tc in range(tcs):
    main()
