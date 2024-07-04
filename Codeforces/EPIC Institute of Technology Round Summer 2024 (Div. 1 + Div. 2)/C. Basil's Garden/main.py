import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    *a, = map(int, input().split())
    w = 0
    for x in reversed(a):
        w = max(w + 1, x)
    print(w)

tcs = int(input())
for tc in range(tcs):
    main()
