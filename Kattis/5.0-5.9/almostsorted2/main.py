n = int(input())
*a, = map(int, input().split())
b = sorted(a)
l = n
r = -1
for i, (x, y) in enumerate(zip(a, b)):
    if x != y:
        r = i
        if l == n: l = i
print(['No', 'Yes'][l==n or a[l:r+1]==b[r-n:l-n-1:-1]])
