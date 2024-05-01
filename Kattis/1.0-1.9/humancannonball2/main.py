import math
for _ in range(int(input())):
    v,a,x,l,h = map(float, input().split())
    a*=math.pi/180
    t = x/v/math.cos(a)
    y = v*t*math.sin(a)-.5*9.81*t*t
    print('Not ' * (y>h-1 or y<l+1) + 'Safe')
