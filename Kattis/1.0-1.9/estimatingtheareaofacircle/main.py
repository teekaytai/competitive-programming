from math import pi
*a,_ = open(0)
for l in a:
    r, m, c = map(float, l.split())
    print(pi*r*r, c/m*r*r*4)
