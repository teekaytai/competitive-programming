from math import pi
while True:
    d, v = map(int, input().split())
    if not d: break
    print(((d**3*2/3-4*v/pi)*3/2)**(1/3))
