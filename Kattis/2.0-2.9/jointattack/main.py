from fractions import *
from functools import reduce
input()
print(reduce(lambda t, x: x+1/t, map(Fraction, reversed(input().split()))))
