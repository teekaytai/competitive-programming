from itertools import combinations
from math import prod
from operator import itemgetter

n = int(input())
a = [(*map(int, input().split()),) for _ in range(n)]
print(min(abs(prod(map(itemgetter(0), comb)) - sum(map(itemgetter(1), comb))) for k in range(1, n + 1) for comb in combinations(a, k)))
