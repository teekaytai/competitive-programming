import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n, m = map(int, input().split())
    print(sum((n+b)//(b*b) for b in range(1, min(m+1, 2000))) - 1)

tcs = int(input())
for tc in range(tcs):
    main()
