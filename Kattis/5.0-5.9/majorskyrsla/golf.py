n,k=map(int,input().split())
*a,=range(1,n+1)
for i in range(n-1,p:=0,-1):
 if k>=i:p=p or i;k-=i
 elif p:a[p:i-1:-1]=a[i:p+1];p=0
a[p::-1]=a[:p+1]
print(*a)