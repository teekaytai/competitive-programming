from collections import defaultdict
while n:=int(input()):
    d = defaultdict(list)
    for _ in range(n):
        n, *a = input().split()
        for c in a: d[c].append(n)
    for k, v in sorted(d.items()):
        print(k, *sorted(v))
    print()
