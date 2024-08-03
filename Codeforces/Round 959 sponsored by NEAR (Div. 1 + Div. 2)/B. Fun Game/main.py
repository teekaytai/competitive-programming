import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    *s, = map(int, input())
    *t, = map(int, input())
    b = False
    for x, y in zip(s, t):
        b |= x == 1
        if y and not b:
            print('NO')
            break
    else:
        print('YES')


tcs = int(input())
for tc in range(tcs):
    main()
