import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, a, b = [int(x) for x in input().split()]
    q, r = divmod(n, 3)
    print(min(a * r, b) + min(a*3, b) * q)

tcs = int(input())
for tc in range(tcs):
    main()
