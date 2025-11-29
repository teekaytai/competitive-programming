from collections import defaultdict
import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    g = defaultdict(list)
    for _ in range(n):
        x, r = map(int, input().split())
        u = x - r
        v = x + r
        g[u].append(v)
        g[v].append(u)
    seen = set()
    t = 0
    for u in g:
        if u in seen: continue
        seen.add(u)
        st = [u]
        E = 0
        V = 1
        while st:
            u = st.pop()
            vs = g[u]
            E += len(vs)
            for v in vs:
                if v in seen: continue
                seen.add(v)
                st.append(v)
                V += 1
        E //= 2
        t += min(E, V)
    print(t)

main()
