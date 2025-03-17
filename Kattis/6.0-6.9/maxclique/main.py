def main():
    n, m, *a = map(int, open(0).read().split())
    g = [0] * n
    for i in range(0, 2 * m, 2):
        u = a[i]
        v = a[i + 1]
        g[u] |= 1 << v
        g[v] |= 1 << u
    best = 0
    s = [((1 << n) - 1, 0)]
    while s:
        a, c = s.pop()
        best = max(best, c)
        m = 0
        for i in range(a.bit_count()):
            b = a & -a
            a ^= b
            m += b
            if i + c < best: continue
            s.append((m & g[b.bit_length() - 1], c + 1))
    print(best)

main()
