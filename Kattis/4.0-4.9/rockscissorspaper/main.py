O = 'RSP'
for _ in range(int(input())):
    H, W, n = map(int, input().split())
    g = [[*input()] for _ in range(H)]
    for _ in range(n):
        G = [[*R] for R in g]
        for r in range(H):
            for c in range(W - 1):
                if g[r][c] == g[r][c+1]: continue
                if (O.find(g[r][c]) - O.find(g[r][c+1])) % 3 == 2: G[r][c+1] = g[r][c]
                else: G[r][c] = g[r][c+1]
        for r in range(H - 1):
            for c in range(W):
                if g[r][c] == g[r+1][c]: continue
                if (O.find(g[r][c]) - O.find(g[r+1][c])) % 3 == 2: G[r+1][c] = g[r][c]
                else: G[r][c] = g[r+1][c]
        g = G
    for R in g:
        print(''.join(R))
    print()
