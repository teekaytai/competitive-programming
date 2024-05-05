n, m = map(int, input().split())
*T, = map(int, input().split())
d = {}
for _ in range(n):
    s, v = input().split()
    d[s] = int(v)
for t in T:
    x = 0
    for _ in range(t):
        s, v = input().split()
        x += d[s] - int(v)
    print(x)
