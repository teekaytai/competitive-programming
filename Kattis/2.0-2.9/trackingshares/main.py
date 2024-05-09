from collections import defaultdict
from itertools import accumulate
D = defaultdict(int)
for _ in range(int(input())):
    a = []
    for _ in range(int(input())):
        n, d = map(int, input().split())
        a.append((d, n))
    a.sort()
    D[a[0][0]] += a[0][1]
    for x, y in zip(a, a[1:]):
        D[y[0]] += y[1] - x[1]
print(*accumulate(v for _, v in sorted(D.items())))
