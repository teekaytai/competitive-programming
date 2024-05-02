import math

for l in open(0):
    r,x,y = map(float, l.split())
    d = math.hypot(x, y)
    if d > r: print('miss'); continue
    a = math.acos(d/r)*r*r-d*(r*r-d*d)**.5
    print(math.pi*r*r-a, a)
