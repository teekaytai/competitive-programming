import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    a, b = input().split()
    print(b[0]+a[1:], a[0]+b[1:])

tcs = int(input())
for tc in range(tcs):
    main()
