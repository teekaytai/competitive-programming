from collections import Counter
n, m = map(int, input().split())
c = Counter()
for i in range(1, m+1): c[i] = 0
c.update(map(int, input().split()))
m = min(c.values())
a = [k for k, v in sorted(c.items()) if v==m]
print(len(a))
print(*a)
