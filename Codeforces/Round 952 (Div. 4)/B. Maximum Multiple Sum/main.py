import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    print(max((sum(i for i in range(x, n+1, x)), x) for x in range(2, n+1))[1])

tcs = int(input())
for tc in range(tcs):
    main()
