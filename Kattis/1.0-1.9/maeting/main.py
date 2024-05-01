from collections import Counter
c = Counter()
for _ in range(int(input())):c[input()] = 0
for _ in range(int(input())):
    _, *a = input().split()
    c.update(a)
for k, v in c.most_common():
    print(v, k)
