from math import prod
n, m = map(int, input().split())
print(max(map(prod, (map(int,input().split()) for _ in range(n)))) - m)
