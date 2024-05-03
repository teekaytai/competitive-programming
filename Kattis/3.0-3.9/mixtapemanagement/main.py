n = int(input())
*a, = map(int, input().split())
I = sorted(range(n), key=a.__getitem__)
res = [[] for _ in range(n)]
for i, p in enumerate(I):
    res[p].append('2')
    for j in range(i+1, n):
        res[I[j]].append('1' if I[j] < p else '3')
print(*map(''.join, res))
