from functools import reduce
*a, = open(0)
for i, l in enumerate(a[2::2], start=1):
    print(f'Case #{i}:', reduce(int.__xor__, map(int, l.split())))
