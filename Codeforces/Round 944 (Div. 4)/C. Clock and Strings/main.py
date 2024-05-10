import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    a, b, c, d = map(int, input().split())
    a, b = sorted((a, b))
    print('YES' if (a<c<b) ^ (a<d<b) else 'NO')

tcs = int(input())
for tc in range(tcs):
    main()
