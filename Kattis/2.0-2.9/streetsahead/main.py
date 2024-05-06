n, q = map(int, input().split())
d = {input(): i for i in range(n)}
for _ in range(q):
    s, t = input().split()
    print(abs(d[s] - d[t]) - 1)
