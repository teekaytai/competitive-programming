import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    s = sorted(a)
    if a == s:
        print(-1)
    else:
        ans = float('inf')
        for i in range(n):
            if a[i] != s[i]:
                ans = min(ans, max(s[i] - s[0], s[-1] - s[i]))
        print(ans)

tcs = int(input())
for tc in range(tcs):
    main()
