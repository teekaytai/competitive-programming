from itertools import permutations
*a, = set(open(0).read().split())
print(*sorted({w1+w2 for w1, w2 in permutations(a, 2)}), sep='\n')
