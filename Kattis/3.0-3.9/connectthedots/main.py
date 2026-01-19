from itertools import pairwise
for I in open(0).read().split('\n\n'):
    g = [list(row) for row in I.split()]
    a = []
    for r, row in enumerate(g):
        for c, cell in enumerate(row):
            if cell != '.':
                i = int(cell) if cell.isdigit() else ord(cell) - 87 if cell.islower() else ord(cell) - 29
                a += [None] * max(i - len(a) + 1, 0)
                a[i] = r, c
    for (r1, c1), (r2, c2) in pairwise(a):
        if r1 == r2:
            for c in range(*sorted((c1, c2))):
                x = g[r1][c]
                g[r1][c] = '-' if x == '.' else '+' if x == '|' else x
        else:
            for r in range(*sorted((r1, r2))):
                x = g[r][c1]
                g[r][c1] = '|' if x == '.' else '+' if x == '-' else x
    print(*map(''.join, g), sep='\n')
    print()
