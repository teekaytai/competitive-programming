from itertools import permutations
from math import gcd

input()
for perm in permutations(map(int, input().split())):
    if all(gcd(a, b) > 1 for a, b in zip(perm, perm[1:])):
        print(*perm)
        break
else:
    print('Neibb')
