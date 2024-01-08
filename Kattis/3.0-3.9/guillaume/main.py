input()
s=input()
mx=0
W=int(s[-1]=='G')
L=int(s[-1]=='A')
w=l=0
for i,c in enumerate(reversed(s), start=1):
    w+=c=='G'
    l+=c=='A'
    r=w/(w+l) if w+l else 0
    if r>mx:
        W=w;L=l;mx=r
print(f'{W}-{L}')
