I=input
def f(i):
 if p[i]-i:p[i]=f(p[i])
 return p[i]
for t in[0]*int(I()):
 *p,=range(5**6);s=[1]*5**6
 for w,u,v in sorted([*map(int,I().split())][::-1]for _ in[0]*~-int(I(I()))):t+=s[u:=f(u)]*s[v:=f(v)]*-~w-1;p[v]=u;s[u]+=s[v]
 print(t)