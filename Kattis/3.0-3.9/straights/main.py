from collections import Counter
n = int(input())
C = Counter(map(int, input().split()))
p = -1
x = 0
t = 0
for k, v in sorted(C.items()):
    t += v if k != p + 1 else max(v - x, 0)
    p = k
    x = v
print(t)
