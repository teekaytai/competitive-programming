from collections import defaultdict
d = defaultdict(set)
for _ in range(int(input())):
    a, b = input().rsplit(maxsplit=1)
    d[b].add(a)
for k, v in sorted(d.items()):
    print(k, len(v))
