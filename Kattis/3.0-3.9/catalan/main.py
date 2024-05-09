from math import comb
_, *a = map(int, open(0))
for x in a: print(comb(2*x,x)//(x+1))
