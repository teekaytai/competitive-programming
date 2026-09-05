import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    t = 1 if a[-1] > 0 else 0
    if n == 1:
        print(t)
        return
    b = [a[i] - 2 * a[i + 1] for i in range(n - 1)]
    if any(x < 0 for x in b):
        print(-1)
        return
    print(max(max(b), t))

tcs = int(input())
for tc in range(tcs):
    main()
