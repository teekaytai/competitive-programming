import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, m = [int(x) for x in input().split()]
    a = [1] * n + [-1] * m
    t = abs(n - m)
    print(sum(t % i == 0 for i in range(1, t + 1)) if t else 1)
    print(*a)

tcs = int(input())
for tc in range(tcs):
    main()
