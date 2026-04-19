import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, m = [int(x) for x in input().split()]
    g = [[] for _ in range(n)]
    for _ in range(m):
        u, v = [int(x) - 1 for x in input().split()]
        g[u].append(v)
    st = [0]
    seen = [0] * n
    seen[0] = 1
    t = 1
    while st:
        u = st.pop()
        for v in g[u]:
            if seen[v]: continue
            seen[v] = 1
            t += 1
            st.append(v)
    print(t)

main()
