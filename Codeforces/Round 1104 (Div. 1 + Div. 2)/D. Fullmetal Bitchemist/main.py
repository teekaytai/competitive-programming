import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    s = input()
    dp0 = dp1 = dp10 = dp01 = dp00 = dp11 = dp2 = 0
    ans = 0
    for b in s:
        if b == '0':
            ans += dp0 + dp10 + dp11 + dp2 + 1
            dp0, dp1, dp10, dp01, dp00, dp11, dp2 = 1 + dp01, 0, dp1, 0, dp0 + dp11, dp10 + dp2, dp00
        else:
            ans += dp1 + dp01 + dp00 + dp2 + 1
            dp0, dp1, dp10, dp01, dp00, dp11, dp2 = 0, 1 + dp10, 0, dp0, dp01 + dp2, dp1 + dp00, dp11
    print(ans)

tcs = int(input())
for tc in range(tcs):
    main()
