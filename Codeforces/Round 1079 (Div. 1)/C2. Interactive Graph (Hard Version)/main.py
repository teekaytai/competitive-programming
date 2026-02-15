import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def q(k):
    print('?', k, flush=True)
    p = [int(x) - 1 for x in input().split()]
    # printerr(p)
    if p == [-2]:
        exit()
    return p[1:]

def a(g):
    print('!', sum(map(len, g)), flush=True)
    for u, vs in enumerate(g):
        for v in vs:
            print(u + 1, v + 1, flush=True)

def main():
    n = int(input())
    if n == -1:
        exit()
    # printerr(n)
    cs = [0] * n
    g = [[] for _ in range(n)]
    st = [0]
    k = 2
    while True:
        # printerr(st)
        p = q(k)
        l = len(p)
        if not p:
            break
        while st and (l == 1 or st[-1] != p[-2]):
            u = st.pop()
            cs[u] = sum(cs[v] for v in g[u]) + 1
        if st:
            g[st[-1]].append(p[-1])
        if cs[p[-1]] != 0:
            k += cs[p[-1]]
        else:
            st.append(p[-1])
            k += 1
    a(g)

tcs = int(input())
for tc in range(tcs):
    main()
