import math
*a, _ = open(0)
for l in a:
    r, h, s = map(float, l.split())
    print(f'{(2*(h*h-r*r)**.5+2*(math.pi-math.acos(r/h))*r)*(1+s/100):.2f}')
