d = {}
m = int(input())
for i, x in enumerate(map(int, input().split())):
    if x in d: m = min(m, i - d[x])
    d[x] = i
print(m)
