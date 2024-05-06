from collections import Counter
for _ in range(int(input())):
    c = Counter()
    for _ in range(int(input())):
        k, v = input().split()
        c[k] += int(v)
    a = sorted((-v, k) for k, v in c.items())
    print(len(a))
    for v, k in a: print(k, -v)
