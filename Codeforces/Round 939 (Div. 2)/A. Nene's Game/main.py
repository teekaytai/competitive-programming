import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    k, q = map(int, input().split())
    *a, = map(int, input().split())
    *n, = map(int, input().split())
    mn = min(a)
    print(*[min(mn-1, x) for x in n])

tcs = int(input())
for tc in range(tcs):
    main()
