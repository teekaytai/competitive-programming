for x in open(0):
    m, p, l, e, r, s, n = map(int, x.split())
    for _ in range(n):
        m, p, l = p//s, l//r, m*e
    print(m)
