import math
X,Y,n = map(int, input().split())
a = []
for _ in range(n):
    x,y,r = map(int, input().split())
    a.append(math.dist((X, Y), (x, y)) - r)
a.sort()
print(max(math.floor(a[2]), 0))
