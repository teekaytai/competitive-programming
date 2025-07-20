import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, m = map(int, input().split())
    print('YES' if n>1 and m>1 and ((n>2) or (m>2)) else 'NO')

tcs = int(input())
for tc in range(tcs):
    main()
