D = [(0, 0), (0, 1), (1, 1), (1, 0), (0, 0), (1, 1), (0, 1), (1, 0)]
N = len(D)
a = [[int(x) if x != '_' else -1 for x in input().split()] for _ in range(2)]
p = [0.] * N
for c in range(0, 10, 2):
    for i in range(N):
        r1, dc1 = D[i]
        r2, dc2 = D[(i + 1) % N]
        c1 = c + dc1
        c2 = c + dc2
        v1 = a[r1][c1]
        v2 = a[r2][c2]
        if v1 > 0 and v2 > 0:
            p[i] = v2 / v1
for c in range(0, 10, 2):
    for i in range(N * 2):
        if not p[i % N]: continue
        r1, dc1 = D[i % N]
        r2, dc2 = D[(i + 1) % N]
        c1 = c + dc1
        c2 = c + dc2
        v1 = a[r1][c1]
        v2 = a[r2][c2]
        if v1 > 0 and v2 < 0:
            a[r2][c2] = round(v1 * p[i % N])
        elif v2 > 0 and v1 < 0:
            a[r1][c1] = round(v2 / p[i % N])
print(*a[0])
print(*a[1])
