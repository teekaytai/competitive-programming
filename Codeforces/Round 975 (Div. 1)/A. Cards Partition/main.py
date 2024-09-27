import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n, k = map(int, input().split())
    *a, = map(int, input().split())
    mx = max(a)
    s = sum(a)
    sz = min((s+k)//mx, n)
    for i in range(sz, 0, -1):
        if -s%i <= k:
            print(i)
            break

tcs = int(input())
for tc in range(tcs):
    main()
