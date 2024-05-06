from math import pi
d, a, b, h = map(int, open(0))
x = pi*d*d/4
y = (a+b)/2*h
print(['Trapizza!','Jafn storar!','Mahjong!'][(x>y)+(x>=y)])
