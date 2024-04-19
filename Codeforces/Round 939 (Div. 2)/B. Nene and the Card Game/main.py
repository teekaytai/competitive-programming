import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    *a, = map(int, input().split())
    p = [0] * (n+1)
    t = 0
    for x in a:
        t += p[x]
        p[x] = 1
    print(t)

tcs = int(input())
for tc in range(tcs):
    main()
