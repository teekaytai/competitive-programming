from math import dist
p = [0]*9
for r in range(3):
    for c, i in enumerate(map(int, input().split())):
        p[i-1] = r, c
print(sum(dist(a,b) for a,b in zip(p, p[1:])))
