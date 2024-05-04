from itertools import combinations
*a, x, y = map(int, input().split())
a.sort(reverse=True)
for t in combinations(a, 3):
    if sum(t) == x:
        print(*t, *(v for v in a if v not in t))
