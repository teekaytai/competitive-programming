from math import *
for _ in range(int(input())):
    n = int(input())
    a = 90
    x = 0
    y = 0
    for _ in range(n):
        da, l = map(float, input().split())
        a += da
        x += l * cos(a*pi/180)
        y += l * sin(a*pi/180)
    print(x, y)
