import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def f(a, k):
    b = [min(x % k, k - x % k) for x in a]
    b.sort()
    return b

def main():
    n, k = map(int, input().split())
    *s, = map(int, input().split())
    *t, = map(int, input().split())
    print(['NO', 'YES'][f(s, k) == f(t, k)])

tcs = int(input())
for tc in range(tcs):
    main()
