from collections import Counter
n, k, l = map(int, input().split())
a = [tuple(map(int, input().split())) for _ in range(n)]
b = [False] * n
c = Counter()
for i, (t, s) in enumerate(a):
    if c[s] < l:
        b[i] = True
        c[s] += 1
        k -= 1
        if k == 0: break
else:
    for i in range(n):
        if b[i]: continue
        b[i] = True
        k -= 1
        if k == 0: break
print(*(t for (t, _), x in zip(a, b) if x), sep='\n')
