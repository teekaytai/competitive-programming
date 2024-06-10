import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    *a, = map(int, input().split())
    if a[0] == a[-1]:print('NO')
    else:
        print('YES')
        if a[0] == a[1]:
            print('R'+'B'*(n-1))
        else:
            print('B'*(n-1)+'R')

tcs = int(input())
for tc in range(tcs):
    main()
