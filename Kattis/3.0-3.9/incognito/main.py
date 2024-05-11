from collections import Counter
import math
for _ in range(int(input())):
    c = Counter(input().split()[1] for _ in range(int(input())))
    print(math.prod(x+1 for x in c.values())-1)
