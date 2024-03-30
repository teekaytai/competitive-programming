import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n, x, y = map(int, input().split())
    *a, = map(int, input().split())
    a.sort()
    s = 0
    u = a[0]
    for v in a:
        s += (v-u==2)
        u = v
    print(s + ((a[0] - a[-1])%n == 2) + x - 2)

tcs = int(input())
for tc in range(tcs):
    main()
