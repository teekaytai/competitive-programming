import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, k = map(int, input().split())
    *a, = map(int, input().split())
    *b, = map(int, input().split())
    k %= 2
    ans0 = -1000000000000000
    ans = -1000000000000000
    s0 = 0
    s1 = 0
    for x, y in zip(a, b):
        s0 = max(s0, 0)
        s0 += x
        ans0 = max(ans0, s0)
        s1 = max(s1, 0)
        s1 += x
        s1 = max(s1, s0 + y)
        ans = max(ans, s1)
    print(ans if k else ans0)

tcs = int(input())
for tc in range(tcs):
    main()
