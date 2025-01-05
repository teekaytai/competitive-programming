import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or len(args) == 1 and args[0] or args

def main():
    n, m = map(int, input().split())
    print(max(n,m)+1)

tcs = int(input())
for tc in range(tcs):
    main()
