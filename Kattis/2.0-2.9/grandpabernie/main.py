from collections import defaultdict
n = int(input())
d = defaultdict(list)
for _ in range(n):
    a, b = input().split()
    d[a].append(int(b))
for v in d.values(): v.sort()
for _ in range(int(input())):
    a, b = input().split()
    print(d[a][int(b)-1])
