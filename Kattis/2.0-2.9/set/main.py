from itertools import combinations
a = open(0).read().split()
r = []
for x,y,z in combinations(range(12), 3):
    if all(a[x][i]!=a[y][i]!=a[z][i]!=a[x][i] or a[x][i]==a[y][i]==a[z][i] for i in range(4)):
        r.append((x+1, y+1, z+1))
if not r: print('no sets')
for p in r:
    print(*p)
