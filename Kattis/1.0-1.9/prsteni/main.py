from math import gcd
input()
b, *a = map(int, input().split())
for c in a:
    g = gcd(b, c)
    print(f'{b//g}/{c//g}')
