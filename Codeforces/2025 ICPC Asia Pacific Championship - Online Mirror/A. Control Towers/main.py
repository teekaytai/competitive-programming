import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, m = map(int, input().split())
    g = [input() for _ in range(n)]
    t = 0
    dp = [[0] * m for _ in range(n)]
    dp2 = [[0] * m for _ in range(n)]
    rs = [0] * n
    cs = [0] * m
    for r in range(n):
        for c in range(m):
            if g[r][c] != '.': continue
            dp[r][c] = 1
            rs[r] += 1
            cs[c] += 1
    for r in range(n):
        for c in range(m):
            if g[r][c] != '.': continue
            t -= (rs[r] + cs[c] - 2) ** 2 * 2 - (rs[r] + cs[c] - 2) + (rs[r] - 1) * (rs[r] - 2) + (cs[c] - 1) * (cs[c] - 2)
    for _ in range(3):
        rs2 = [0] * n
        cs2 = [0] * m
        for r in range(n):
            for c in range(m):
                if g[r][c] != '.': continue
                v = rs[r] + cs[c] - dp[r][c] * 2
                dp2[r][c] = v
                rs2[r] += v
                cs2[c] += v
        rs = rs2
        cs = cs2
        dp, dp2 = dp2, dp
    print(sum(rs) + t)

# tcs = int(input())
# for tc in range(tcs):
main()
