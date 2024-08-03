import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n, m = map(int, input().split())
    g = [list(map(int, input().split())) for _ in range(n)]
    if n == m == 1: print(-1)
    else:
        for r in g:
            print(*(x%(n*m)+1 for x in r))

tcs = int(input())
for tc in range(tcs):
    main()
