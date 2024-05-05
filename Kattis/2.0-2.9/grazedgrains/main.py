import random
n = int(input())
a = []
mnx = mny = 20
mxx = mxy = -10
for _ in range(n):
    x, y, r = map(int, input().split())
    a.append((x, y, r*r))
    mnx = min(mnx, x-r)
    mny = min(mny, y-r)
    mxx = max(mxx, x+r)
    mxy = max(mxy, y+r)
t = 0
for _ in range(100000):
    X = random.random()*(mxx-mnx) + mnx
    Y = random.random()*(mxy-mny) + mny
    t += any((X-x)**2+(Y-y)**2 <= r2 for x,y,r2 in a)
print(t/100000*(mxx-mnx)*(mxy-mny))
