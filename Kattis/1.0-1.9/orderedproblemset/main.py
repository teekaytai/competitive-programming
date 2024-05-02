n, *a = map(int, open(0))
l = []
for i in range(2, n+1):
    if n%i!=0: continue
    s = n//i
    if all(set(a[s*j:s*(j+1)])=={*range(s*j+1, s*(j+1)+1)} for j in range(i)):
        l.append(i)
print(*l or [-1], sep='\n')
