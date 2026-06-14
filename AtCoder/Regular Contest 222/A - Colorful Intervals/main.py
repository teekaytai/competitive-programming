import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, m = [int(x) for x in input().split()]
    mx = 1
    for _ in range(m):
        l, r = [int(x) for x in input().split()]
        mx = max(mx, r - l + 1)
    print(*[i % mx + 1 for i in range(n)])

tcs = int(input())
for tc in range(tcs):
    main()
