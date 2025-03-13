import sys

input = lambda: sys.stdin.readline().rstrip()

def main():
    n, m = map(int, input().split())
    g = [[] for _ in range(n)]
    ws = [[0] * n for _ in range(n)]
    rs = [True] * n
    for _ in range(m):
        u, v, w = map(int, input().split())
        u -= 1; v -= 1
        if v < u: u, v = v, u
        rs[v] = False
        g[u].append(v)
        ws[u][v] = w
        ws[v][u] = w
    t = 0
    for i, (vs, r) in enumerate(zip(g, rs)):
        if not r: continue
        if len(vs) % 2 == 0: print('impossible'); return
        vs.append(i)
        dp = [0] * 2**len(vs)
        for j in range(1, len(dp)):
            if j.bit_count() % 2: continue
            mn = 100000000
            b = j & -j
            bi = b.bit_length() - 1
            s = j ^ b
            S = s
            while S:
                c = S & -S
                S ^= c
                ci = c.bit_length() - 1
                mn = min(mn, dp[s ^ c] + ws[vs[bi]][vs[ci]])
            dp[j] = mn
        t += dp[-1]
    print(t)

main()
