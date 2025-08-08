import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    *a, = map(int, input().split())
    s = set(sorted(a)) - {-1}
    if 0 in s or len(s) > 1:
        print('NO')
    else:
        print('YES')

tcs = int(input())
for tc in range(tcs):
    main()
