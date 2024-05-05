from math import gcd
mn = 1000000000
for l in range(int(input())):
    a, b, c = map(int, input().split())
    mn = min(mn, a+b*c//gcd(b,c))
print(mn)
