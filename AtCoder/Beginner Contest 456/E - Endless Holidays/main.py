import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, m = [int(x) for x in input().split()]
    g = [[i] for i in range(n)]
    for _ in range(m):
        u, v = [int(x) for x in input().split()]
        u -= 1; v -= 1
        g[u].append(v)
        g[v].append(u)
    w = int(input())
    ss = [input() for _ in range(n)]
    seen = [[0] * n for _ in range(w)]
    for i, s in enumerate(ss):
        if s[0] != 'o' or seen[0][i]:
            continue
        st = [(0, i)]
        while st:
            t, u = st.pop()
            if u < 0:
                seen[t][~u] = 2
                continue
            if seen[t][u] == 2:
                continue
            seen[t][u] = 1
            st.append((t, ~u))
            t2 = (t + 1) % w
            for v in g[u]:
                if ss[v][t2] != 'o': continue
                if seen[t2][v] == 1:
                    print('Yes')
                    return
                if seen[t2][v] == 2:
                    continue
                st.append((t2, v))
    print('No')

tcs = int(input())
for tc in range(tcs):
    main()
