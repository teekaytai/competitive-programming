import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or len(args) == 1 and args[0] or args

def main():
    n, l, r = map(int, input().split())
    l-=1
    r-=1
    *a, = map(int, input().split())
    b = sorted(a[:l])
    c = sorted(a[r+1:])
    a = sorted(a[l:r+1])
    t = sum(a)
    s = 0
    for x, y in zip(reversed(a), b):
        if x <= y: break
        s += x - y
    s2 = 0
    for x, y in zip(reversed(a), c):
        if x <= y: break
        s2 += x - y
    print(t - max(s, s2))

tcs = int(input())
for tc in range(tcs):
    main()
