n = int(input())
t = 1
p = 2
while p*p<=n:
    if n%p: p+=1
    else: t+=1; n//=p
print(t)
