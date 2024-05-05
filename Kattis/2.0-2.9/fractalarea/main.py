from math import *
for _ in range(int(input())):
    r, n = map(int, input().split())
    print(pi * r*r * (1 + (1-.75**(n-1))/.25))
