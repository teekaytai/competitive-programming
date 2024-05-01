n = int(input())
a = []
for i in range(1, n+1):
    for j, x in enumerate(map(int,input().split()), start=1):
        if x != -1: a.append((i, j, x))
print(len(a))
for t in a:
    print(*t)
