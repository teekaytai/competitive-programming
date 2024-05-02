from itertools import combinations
*a, = map(int, open(0))
s = sum(a) - 100
for i, j in combinations(range(9), 2):
    if a[i]+a[j] == s:
        for k in range(9):
            if i != k != j: print(a[k])
