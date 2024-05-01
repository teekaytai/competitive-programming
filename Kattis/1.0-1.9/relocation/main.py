n,q = map(int, input().split())
*a, = map(int, input().split())
for _ in range(q):
    x, y, z = map(int, input().split())
    if x==1: a[y-1] = z
    else: print(abs(a[y-1] - a[z-1]))
