from collections import Counter
c = Counter(open(0))
a, b = c.most_common(2)
print(a[0] if a[1]>b[1] else 'Runoff!')
