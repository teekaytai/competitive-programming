from collections import Counter
c = Counter(map(str.strip, open(0)))
t = sum(c.values())
for k, v in sorted(c.items()):
    print(k, v/t*100)
