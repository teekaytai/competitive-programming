n, t = map(int, input().split())
*a, = map(int, input().split())
a.append(t)
c=0
i=0
while c <= t:
    c+=a[i]
    i+=1
print(i-1)
