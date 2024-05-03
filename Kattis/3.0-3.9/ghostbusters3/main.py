from math import comb
a, b = map(int, input().split())
if a <= b: print(comb(b,a)%1000000007)
else: print(comb(a-1,b-1)%1000000007)
