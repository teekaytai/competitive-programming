
import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    *a, = map(int, input().split())
    p, q = 0, 0
    for x in a:
        p, q = max(abs(p+x), abs(q+x)), min(p+x, q+x)
    print(p)

tcs = int(input())
for tc in range(tcs):
    main()
