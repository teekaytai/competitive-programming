def f(t):
    h, m = map(int, t.split(':'))
    return h*60+m
for tc in range(1, int(input())+1):
    k = int(input())
    n, m = map(int, input().split())
    r = [0, 0]
    c = [0, 0]
    a = []
    for _ in range(n):
        x, y = map(f, input().split())
        a.extend([(x, 1, 0), (y+k, -1, 1)])
    for _ in range(m):
        x, y = map(f, input().split())
        a.extend([(x, 1, 1), (y+k, -1, 0)])
    a.sort()
    for _, d, i in a:
        c[i] -= d
        if c[i] < 0: r[i] += 1; c[i] += 1
    print(f'Case #{tc}:', *r)
