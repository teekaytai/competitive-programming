n, m, p = map(int, input().split())
a = [tuple(map(int, input().split())) for _ in range(n)]
b = [tuple(map(int, input().split())) for _ in range(m)]
c = [tuple(map(int, input().split())) for _ in range(p)]
def f(a, b):
    ba = [False] * len(a)
    bb = [False] * len(b)
    e = [((p[0] - q[0]) ** 2 + (p[1] - q[1]) ** 2, i, j) for i, p in enumerate(a) for j, q in enumerate(b)]
    e.sort()
    c = 0
    ans = 0.0
    for d, i, j in e:
        if ba[i] or bb[j]: continue
        ba[i] = True
        bb[j] = True
        ans += d ** 0.5
        c += 1
        if c == len(a):
            return ans
print(f(a, b) + f(a, c))
