import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

MOD = 998244353

def main():
    n = int(input())
    s = input()
    pow2 = 1
    ps = 0
    dp0 = 1
    dp2 = 0
    ans = 0
    for c in s:
        if c == '(':
            ps += 1
            ans = (ans + pow2) % MOD
            dp2 = dp2 * 2 % MOD
            if ps >= 2:
                dp2 = (dp2 + dp0) % MOD
        else:
            ps -= 1
            ans = (ans + dp0 + dp2) % MOD
            dp0 = dp0 * 2 % MOD
            if ps >= 1:
                dp0 = (dp0 + dp2) % MOD
            if ps < 2:
                dp2 = 0
        pow2 = pow2 * 2 % MOD
        # printerr(dp0, dp2)
    print(ans)

tcs = int(input())
for tc in range(tcs):
    main()
