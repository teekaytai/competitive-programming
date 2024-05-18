import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    *a, = map(int, input().split())
    x = 0
    l = n
    r = 0
    for k, v in enumerate(a):
        if v != k+1:
            if x and x != k+v: x = -1
            else: x = k+v
            l = min(l, v)
            r = max(r, v)
    t = (l+n)*(2*n-r)-((d:=l+n-r)*(d+1)//2 if l+n>=r+1 else 0)
    print(t + (2*n if x == 0 else 1 if x > 0 else 0))

tcs = int(input())
for tc in range(tcs):
    main()
