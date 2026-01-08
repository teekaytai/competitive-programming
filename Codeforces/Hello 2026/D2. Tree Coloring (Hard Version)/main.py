import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    g = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = [int(x) for x in input().split()]
        u -= 1; v -= 1
        g[u].append(v)
        g[v].append(u)
    sids = [-1] * n
    sids[0] = 0
    lasts = [0]
    ans = [[0]]
    q = [0]
    l = 0
    while q:
        l += 1
        q2 = []
        p = -1
        pc = 0
        for u in q:
            for v in g[u]:
                if sids[v] != -1:
                    continue
                if p != u:
                    pc += 1
                    if p != -1:
                        sid = sids[p]
                        sids[v] = sid
                        ans[sid].append(v)
                        lasts[sid] = l
                    p = u
                q2.append(v)
        if pc > 1:
            sid = sids[p]
            v = q2[0]
            sids[v] = sid
            ans[sid].append(v)
            lasts[sid] = l
        elif pc == 1:
            lasts[sids[p]] = l
        # printerr(q2, ans, lasts)
        if q2:
            sid = 0
            for v in q2:
                if sids[v] != -1:
                    continue
                while sid < len(lasts) and lasts[sid] == l:
                    sid += 1
                if sid == len(lasts):
                    lasts.append(l)
                    ans.append([])
                sids[v] = sid
                ans[sid].append(v)
                lasts[sid] = l
                sid += 1
        q = q2
    print(len(ans))
    for r in ans:
        print(len(r), *(x + 1 for x in r))

tcs = int(input())
for tc in range(tcs):
    main()
