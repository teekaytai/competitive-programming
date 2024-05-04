while True:
    n, m = map(int, input().split())
    if not n: break
    a = []
    for _ in range(n):
        _, _, s, d = map(int, input().split())
        a.append((s, s+d))
    for _ in range(m):
        x, y = map(int, input().split())
        print(sum(e>x and x+y>s for s, e in a))
