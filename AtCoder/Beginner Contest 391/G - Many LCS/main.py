import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def MSB(x):
    return x and 1 << (x.bit_length() - 1)

MOD = 998244353

def main():
    n, m = map(int, input().split())
    s = input()
    se = set(s)
    a = [''.join(str(int(c == d)) for d in s) for c in se]
    ts = []
    for i in range(1 << n):
        t = []
        for x in a:
            y = 0
            b = 1 << (n - 1)
            p = 0
            c0 = c1 = 0
            for j in range(n):
                c0, c1 = c1, c1 + (i & b > 0)
                te = max(p, c1) if x[j] != '1' else 1 + c0
                y = y * 2 + (te > p)
                p = te
                b >>= 1
            t.append(y)
        ts.append(t)
    p = 26 - len(se)
    dp = [0] * (1 << n)
    dp[0] = 1
    for _ in range(m):
        dp2 = [v * p % MOD for v in dp]
        for i, (v, t) in enumerate(zip(dp, ts)):
            for j in t:
                dp2[j] = (dp2[j] + v) % MOD
        dp = dp2
    ans = [0] * (n + 1)
    for i, v in enumerate(dp):
        ans[c] = (ans[c := i.bit_count()] + v) % MOD
    print(*ans)

main()
