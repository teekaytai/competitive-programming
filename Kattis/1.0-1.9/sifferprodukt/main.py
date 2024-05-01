from math import prod
x = input()
while len(x) > 1:
    x = str(prod(int(d) or 1 for d in x))
print(x)
