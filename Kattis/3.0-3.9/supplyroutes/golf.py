def F(i):
 if P[i]-i:P[i]=i=F(P[i])
 return i
def U(_,u,v):P[F(u)]=F(v)
(n,m,q),*I=[(0,*map(int,l.split()))[-3:]for l in open(0)]
Q=I[:m-1:-1]
*P,=range(n)
for E in{*I[:m]}-{*Q}:U(*E)
[*map(print,['un'*(F(u)!=F(v))+'safe'for t,u,v in Q if t or U(t,u,v)][::-1])]