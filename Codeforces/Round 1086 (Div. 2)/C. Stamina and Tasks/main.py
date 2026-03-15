import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = []
    for _ in range(n):
        c, p = map(int, input().split())
        a.append((c, p))
    best = 0
    for c, p in reversed(a):
        best = max(c + (1 - p/100) * best, best)
    print(best)

tcs = int(input())
for tc in range(tcs):
    main()
