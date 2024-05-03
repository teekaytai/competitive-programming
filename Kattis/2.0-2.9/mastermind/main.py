from collections import Counter
n, a, b = input().split()
r = 0
c1 = Counter()
c2 = Counter()
for x, y in zip(a, b):
    if x == y: r += 1
    else:
        c1[x] += 1
        c2[y] += 1
print(r, sum(min(v, c2[k]) for k, v in c1.items()))
