import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    g = [input() for _ in range(n)]
    ans = [0] * (2 * n)
    dp = []
    for r, row in enumerate(g):
        dp2 = []
        for c, cell in enumerate(row):
            d = cell == '@'
            if r == c == 0:
                lo, hi = 0, 0
            elif r == 0:
                lo, hi = dp2[-1]
            elif c == 0:
                lo, hi = dp[c]
            else:
                lo1, hi1 = dp[c]
                lo2, hi2 = dp2[-1]
                assert lo1 <= hi2 + 1 and lo2 <= hi1 + 1
                lo = min(lo1, lo2)
                hi = max(hi1, hi2)
            lo += d
            hi += d
            dp2.append((lo, hi))
            ans[lo] += 1
            ans[hi + 1] -= 1
        dp = dp2
    ans.pop()
    for i in range(len(ans) - 1):
        ans[i + 1] += ans[i]
    for x in ans:
        print(x)

main()
