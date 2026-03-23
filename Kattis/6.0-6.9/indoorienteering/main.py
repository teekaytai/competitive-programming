from itertools import combinations

n, L = map(int, input().split())
ds = [[int(x) for x in input().split()] for _ in range(n)]
if n == 2:
    print('possible' if ds[0][1] * 2 == L else 'impossible')
    exit()
if n == 3:
    print('possible' if ds[0][1] + ds[1][2] + ds[2][1] == L else 'impossible')
    exit()

def dfs(f, m, p, t):
    if not m:
        f(t + ds[p][n - 1])
        return
    ma = m
    while ma:
        b = ma & -ma
        ma -= b
        bi = b.bit_length() - 1
        dfs(f, m - b, bi, t + ds[p][bi])

dp = set()
for x in range(n - 1):
    def f(t):
        if L - t in dp:
            print('possible')
            exit()
    S = {*range(x), *range(x + 1, n - 1)}
    for l in combinations(S, (n - 2) // 2):
        r = list(S - {*l})
        if n % 2 == 0 and min(l) > min(r): continue
        dp.clear()
        m = sum(1 << i for i in l)
        m2 = sum(1 << i for i in r)
        for s in r:
            dfs(dp.add, m2 - (1 << s), s, ds[s][x])
        for s in l:
            dfs(f, m - (1 << s), s, ds[s][x])
print('impossible')
