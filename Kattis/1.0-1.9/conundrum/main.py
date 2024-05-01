from itertools import cycle
print(sum(x!=y for x,y in zip(input(),cycle('PER'))))
