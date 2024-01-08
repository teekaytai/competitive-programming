from math import gcd
a,b,c,d=map(int, input().split())
l=c*d//gcd(c,d)
print(b//l-(a-1)//l)
