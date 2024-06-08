import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    *a, = map(int, input().split())
    print(min(max(a[i], a[i+1])for i in range(n-1)) - 1)

tcs = int(input())
for tc in range(tcs):
    main()
