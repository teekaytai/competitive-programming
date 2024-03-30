import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n, k = map(int, input().split())
    if k == n: print(*[1] * n)
    elif k == 1: print(*range(1, n+1))
    else: print(-1)

tcs = int(input())
for tc in range(tcs):
    main()
