import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    x, y = map(int, input().split())
    print(2 if y > x else 3 if x - y > 1 and y > 1 else -1)

tcs = int(input())
for tc in range(tcs):
    main()
