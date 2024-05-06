n, m = map(int, input().split())
d = {}
for _ in range(n):
    s, v = input().split()
    d[s] = int(v)
for _ in range(m):
    x = 0
    while (t := input()) != '.':
        x += sum(d.get(w, 0) for w in t.split())
    print(x)
