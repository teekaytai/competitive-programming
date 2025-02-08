import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

class UF:
    def __init__(self, n):
        self.ps = list(range(n + 1))

    def find(self, i):
        if i == self.ps[i]:
            return self.ps[i]
        self.ps[i] = self.find(self.ps[i])
        return self.ps[i]

    def union(self, i, j):
        ri = self.find(i)
        rj = self.find(j)
        if ri != rj:
            self.ps[rj] = ri

def main():
    n, m = map(int, input().split())
    g = [[] for _ in range(n + 1)]
    for i in range(1, m+1):
        u, v = map(int, input().split())
        g[u].append((v, i))
        if u != v: g[v].append((u, i))
    seen = [False] * (n + 1)
    reee = [False] * (m + 1)
    halp = []
    e = []
    ans = []
    uf = UF(n)
    for s in range(1, n+1):
        if seen[s]: continue
        seen[s] = s
        st = [s]
        while st:
            u = st.pop()
            for v, i in g[u]:
                if reee[i]: continue
                reee[i] = True
                if seen[v]:
                    e.append((i, u))
                else:
                    seen[v] = s
                    uf.union(s, v)
                    st.append(v)
        halp.append(s)
    while len(halp) > 1:
        i, u = e.pop()
        v = halp.pop()
        if uf.find(u) == uf.find(v):
            ans.append((i, u, halp[-1]))
            uf.union(u, halp[-1])
        else:
            ans.append((i, u, v))
            uf.union(u, v)
    print(len(ans))
    for t in ans: print(*t)

# tcs = int(input())
# for tc in range(tcs):
main()
