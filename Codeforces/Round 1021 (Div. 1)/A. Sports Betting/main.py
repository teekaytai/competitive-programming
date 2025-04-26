import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    *a, = map(int, input().split())
    a.sort()
    p = -1
    c = 0
    for x in a:
        if x == p:
            c += 1
        elif x == p + 1:
            c = 3 if c >= 2 else 1
        else:
            c = 1
        p = x
        if c == 4:
            print('Yes')
            return
    print('No')

tcs = int(input())
for tc in range(tcs):
    main()
