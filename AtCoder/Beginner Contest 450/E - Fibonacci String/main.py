from collections import Counter
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    x = input()
    y = input()
    xc = Counter(x)
    yc = Counter(y)
    xs = [1, 0]
    ys = [0, 1]
    ts = [len(x), len(y)]
    while ts[-1] < int(1e18):
        xs.append(xs[-2] + xs[-1])
        ys.append(ys[-2] + ys[-1])
        ts.append(ts[-2] + ts[-1])
    pssx = []
    for i in range(26):
        c = chr(97 + i)
        ps = [0]
        for j in range(len(x)):
            ps.append(ps[-1] + (x[j] == c))
        pssx.append(ps)
    pssy = []
    for i in range(26):
        c = chr(97 + i)
        ps = [0]
        for j in range(len(y)):
            ps.append(ps[-1] + (y[j] == c))
        pssy.append(ps)
    def f(k, c):
        cx = xc[c]
        cy = yc[c]
        ans = 0
        # printerr(k, c, cx, cy)
        for i in range(len(ts) - 1, 1, -1):
            if ts[i] <= k:
                # printerr(k, i, xs[i], ys[i])
                ans += cx * xs[i] + cy * ys[i]
                k -= ts[i]
        if k <= len(y):
            ans += pssy[ord(c) - 97][k]
        else:
            ans += cy + pssx[ord(c) - 97][k - len(y)]
        # printerr(ans, k)
        return ans
    # s = y + x
    # t = s + y
    # for i in range(20):
    #     s, t = t, t + s
    # printerr(t[:20])
    q = int(input())
    for _ in range(q):
        l, r, c = input().split()
        l = int(l); r = int(r)
        ans = f(r, c) - f(l - 1, c)
        # if r <= len(t):
        #     v = sum(t[i] == c for i in range(l - 1, r))
        #     assert ans == v, f'{ans} {v}'
        print(ans)

main()
