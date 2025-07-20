import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, l, r = map(int, input().split())
    t = 0
    for _ in range(n):
        x, y = map(int, input().split())
        t += (x <= l) and (y >= r)
    print(t)

main()
