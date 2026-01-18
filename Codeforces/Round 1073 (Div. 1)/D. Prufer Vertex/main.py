import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

MOD = 998244353

def modinv(x, mod=MOD):
    return x if x <= 1 else mod - mod // x * modinv(mod % x, mod) % mod
    # return pow(x, -1, mod)  # Works for non-prime mod and works for x > mod

def moddiv(a, b, mod=MOD):
    return a * modinv(b, mod) % mod

def main():
    n, m = [int(x) for x in input().split()]
    g = [[] for _ in range(n)]
    for _ in range(m):
        u, v = [int(x) - 1 for x in input().split()]
        g[u].append(v)
        g[v].append(u)
    ans = [-1] * (n - 1)
    k = 0
    szs = [0] * n
    rs = [-1] * n
    ps = [-1] * n
    bs = [False] * n
    t = 1
    for i in range(n - 1, -1, -1):
        if rs[i] != -1: continue
        k += 1
        st = [i]
        while st:
            u = st[-1]
            if rs[u] != -1:
                szs[u] = 1 + sum(szs[v] for v in g[u])
                bs[u] = u == n - 2 or any(bs[v] for v in g[u])
                st.pop()
                continue
            rs[u] = i
            for v in g[u]:
                if rs[v] != -1: continue
                st.append(v)
                ps[v] = u
                if i == n - 1 and u != n - 1:
                    ans[v] = 0
        if i != n - 1:
            t = t * szs[i] % MOD
    t = t * pow(n, k - 2, MOD) % MOD
    t1 = moddiv(t, n)
    for i in range(n - 1):
        if ans[i] != -1: continue
        if ps[i] == n - 1:
            ans[i] = 0 if bs[n - 1] and not bs[i] else t * szs[i] % MOD if not bs[i] else t * szs[n - 1] % MOD
        else:
            s = szs[n - 1] + szs[rs[i]]
            ans[i] = moddiv(t1, szs[rs[i]]) * s % MOD if bs[rs[i]] else 0 if bs[n - 1] else t1
    print(*ans)

tcs = int(input())
for tc in range(tcs):
    main()
