from itertools import combinations
from math import perm
n = int(input())
*a, = map(int, input().split())
A = 0 if any(x==y for x, y in combinations(a, 2)) else perm(6-n, 4-n)
print(A, 6**(4-n)-A)
