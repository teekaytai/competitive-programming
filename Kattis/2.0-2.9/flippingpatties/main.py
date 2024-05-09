from collections import Counter
c = Counter()
for _ in range(int(input())):
    d, t = map(int, input().split())
    c[t-d-d] += 1
    c[t-d] += 1
    c[t] += 1
print((c.most_common(1)[0][1]+1)//2)
