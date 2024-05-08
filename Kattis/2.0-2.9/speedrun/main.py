n, m = map(int, input().split())
a = [tuple(map(int, input().split()))[::-1] for _ in range(m)]
a.sort()
c = 0
t = 0
for e, s in a:
    if s >= c: t += 1; c = e
print(['NO','YES'][t >= n])
