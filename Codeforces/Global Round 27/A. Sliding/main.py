import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n, m, r, c = map(int, input().split())
    print((n-r)*(m-1+m)+(m-c))

tcs = int(input())
for tc in range(tcs):
    main()
