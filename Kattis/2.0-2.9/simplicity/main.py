from collections import Counter
s = input()
c = Counter(s)
print(len(s)-sum(v for _, v in c.most_common(2)))
