import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    print(sum(i * (i*2-1) for i in range(1, n+1)), 2*n)
    for i in range(1, n+1):
        print(1, i, *range(n, 0, -1))
        print(2, i, *range(n, 0, -1))

tcs = int(input())
for tc in range(tcs):
    main()
