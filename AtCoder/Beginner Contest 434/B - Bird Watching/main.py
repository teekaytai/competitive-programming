import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, m = map(int, input().split())
    s = [0] * m
    cs = [0] * m
    for _ in range(n):
        a, b = map(int, input().split())
        s[a - 1] += b
        cs[a-1] += 1
    for x, y in zip(s, cs):
        print(x / y)

main()
