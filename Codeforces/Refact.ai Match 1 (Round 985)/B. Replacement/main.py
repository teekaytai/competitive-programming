import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    x = sum(map(int, input()))
    *a, = map(int, input())
    for b in a:
        if x == n or x == 0:
            print('NO')
            return
        n -= 1
        x -= b == 0
    print('YES')

tcs = int(input())
for tc in range(tcs):
    main()
