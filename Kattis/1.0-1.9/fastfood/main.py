for _ in range(int(input())):
    n, m = map(int, input().split())
    a = []
    for _ in range(n):
        _, *s, p = map(int, input().split())
        a.append((s, p))
    *c, = map(int, input().split())
    t = 0
    for s, p in a:
        t += min(c[x-1] for x in s) * p
    print(t)
