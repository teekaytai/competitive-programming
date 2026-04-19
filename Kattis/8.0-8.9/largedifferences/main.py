from itertools import chain, permutations
import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def f(a):
    return min(abs(a[i] - a[i+1]) for i in range(len(a) - 1))

def main():
    n = int(input())
    *a, = map(int, input().split())
    up_m = (n+1)//2
    lo_m = n//2
    a.sort()
    if n < 5:
        print(max(f(p) for p in permutations(a)))
    elif n% 2:
        mn = min(abs(a[i] - a[i+up_m]) for i in range(lo_m))
        *b, = sorted(abs(a[i] - a[i+lo_m]) for i in range(up_m))
        print(min(mn, b[1]))
    else:
        print(max(map(f, [
            [*chain(*((a[lo_m + i], a[i]) for i in range(lo_m)))],
            [*chain(*((a[i], a[lo_m + i]) for i in range(lo_m)))],
        ]
        )))


main()
