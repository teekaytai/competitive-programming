from functools import reduce
_, *a = open(0)
s = reduce(set.intersection, (set(l.split()) for l in a))
print(len(s))
print(*sorted(s), sep='\n')
