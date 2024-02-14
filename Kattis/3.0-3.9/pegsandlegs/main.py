import sys

input = lambda: sys.stdin.readline().strip()

L, P = map(int, input().split())
dp = [(float(input()), 1.) for _ in range(L)]
can = [1] * (L+P)
for _ in range(P):
    l, r, x, y = input().split()
    l = float(l)
    r = float(r)
    x = int(x)-1
    y = int(y)-1
    can[x] = can[y] = 0
    el, pl = dp[x]
    er, pr = dp[y]
    dp.append((el*l+er*r, pl*l+pr*r))
print(max(b*e/p for (e, p), b in zip(dp, can)))
