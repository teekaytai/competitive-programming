import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    if n % 12 != 10:
        print(n % 12, n - n % 12)
    elif n >= 22:
        print(22, n - 22)
    else:
        print(-1)

tcs = int(input())
for tc in range(tcs):
    main()
