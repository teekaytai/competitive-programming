from collections import Counter
input()
*a, = map(int, input().split())
c = Counter(a)
m = max((k for k, v in c.items() if v == 1), default=0)
print(a.index(m) + 1 if m else 'none')
