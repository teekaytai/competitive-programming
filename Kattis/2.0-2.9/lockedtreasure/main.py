import math
_, *a, = open(0)
for l in a:
    x, y = map(int, l.split())
    print(math.comb(x, y-1))
