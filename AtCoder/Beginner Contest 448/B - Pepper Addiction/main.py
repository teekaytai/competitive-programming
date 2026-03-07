import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, m = [int(x) for x in input().split()]
    c = [int(x) for x in input().split()]
    t = 0
    for _ in range(n):
        a, b = [int(x) for x in input().split()]
        a -= 1
        mn = min(c[a], b)
        c[a] -= mn
        t += mn
    print(t)

main()
