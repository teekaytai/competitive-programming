import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    s = set(sorted(map(int, input().split())))
    print(len(s) * 2 - 1)

tcs = int(input())
for tc in range(tcs):
    main()
