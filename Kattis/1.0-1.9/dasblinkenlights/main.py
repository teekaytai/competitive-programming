from math import gcd
a,b,c = map(int, input().split())
print(['no','yes'][a*b//gcd(a,b)<=c])
