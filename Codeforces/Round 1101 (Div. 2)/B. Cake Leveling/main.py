import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    ans = []
    m = 10**10
    t = 0
    for i, x in enumerate(a, 1):
        t += x
        m = min(m, t // i)
        ans.append(m)
    print(*ans)

tcs = int(input())
for tc in range(tcs):
    main()
