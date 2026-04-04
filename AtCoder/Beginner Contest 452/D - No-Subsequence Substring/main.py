import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    s = input()
    t = input()
    m = len(t)
    dp = [-1] * m
    lo = 0
    ans = 0
    for hi, c in enumerate(s):
        for i in range(m - 1, -1, -1):
            d = t[i]
            if c == d:
                dp[i] = hi if i == 0 else dp[i - 1]
        while dp[-1] >= lo:
            lo += 1
        ans += hi - lo + 1
    print(ans)

main()
