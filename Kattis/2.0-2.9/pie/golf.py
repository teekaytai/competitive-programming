_,*L=open(0)
for A,B in zip(L[::2],L[1::2]):
 f=int(A.split()[1]);l=0;h=1e8
 while h-l>1e-5:m=(l+h)/2;f+1>sum(int(r)**2//m for r in B.split())and(h:=m)or(l:=m)
 print(3.14159265359*l)