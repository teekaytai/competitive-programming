import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = input().split()
    s = ''
    for x in a:
        s = min(s+x, x+s)
    print(s)

tcs = int(input())
for tc in range(tcs):
    main()
