from collections import Counter
d = {}
for _ in range(int(input())):
    s = input()
    d[s] = input()
c = Counter()
for _ in range(int(input())):
    s = input()
    if s in d:
        c[s] += 1
a = c.most_common(2)
if not a or len(a) == 2 and a[0][1] == a[1][1]: print('tie')
else:
    print(d[a[0][0]])
