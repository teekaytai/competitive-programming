from math import prod
*s, = map(int, input().split())
print(prod(sum(s)/2-x for x in s)**.5)
