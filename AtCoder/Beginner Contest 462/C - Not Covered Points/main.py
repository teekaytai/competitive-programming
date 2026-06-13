import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = [tuple(map(int, input().split())) for _ in range(n)]
    a.sort()
    mn = n + 1
    t = 0
    for x, y in a:
        t += mn >= y
        mn = min(mn, y)
    print(t)

main()
