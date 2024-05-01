import math
O="ABCDEFGHIJKLMNOPQRSTUVWXYZ '"
_,*a=map(str.strip,open(0))
for l in a:
    print(len(l)+4*math.pi*sum(min(d:=abs(O.find(y)-O.find(x)),28-d)for x,y in zip(l,l[1:]))/28)
