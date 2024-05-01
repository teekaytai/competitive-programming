from collections import Counter
c = Counter(x[0] for x in input().split())
print(c.most_common(1)[0][1])
