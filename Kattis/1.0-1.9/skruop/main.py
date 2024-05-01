_,*a=open(0)
x=7
for l in a:x=[max(x-1,0),min(x+1,10)][l[5]=='o']
print(x)
