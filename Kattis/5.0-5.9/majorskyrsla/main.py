n, k = map(int, input().split())
*a, = range(1, n+1)
p = -1
for i in range(n-1, 0, -1):
    if k>=i:
        if p==-1: p = i
        k -= i
    else:
        if p!=-1:
            a[p:i-1:-1] = a[i:p+1]
            p = -1
if p!=-1:
    a[p::-1] = a[:p+1]
print(*a)
