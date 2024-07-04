import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n, k = map(int, input().split())
    print((n-1)*k+1)

tcs = int(input())
for tc in range(tcs):
    main()
