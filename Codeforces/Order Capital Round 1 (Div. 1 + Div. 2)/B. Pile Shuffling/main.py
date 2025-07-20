import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    t = 0
    for _ in range(n):
        a, b, c, d = map(int, input().split())
        if b > d:
            t += a + b - d
        else:
            t += max(a - c, 0)
    print(t)

tcs = int(input())
for tc in range(tcs):
    main()
