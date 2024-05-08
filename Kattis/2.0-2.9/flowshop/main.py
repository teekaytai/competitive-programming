n, m = map(int, input().split())
d1 = [0] * n
d2 = [0] * n
g = [[*map(int, input().split())] for _ in range(n)]
for l in zip(*g):
    for i, x in enumerate(l):
        d2[i] = max(d1[i], d2[i-1] if i else 0) + x
    d1, d2 = d2, d1
print(*d1)
