l,r,x = map(int, open(0))
for i in range(l, r+1):
    if sum(map(int,str(i))) == x:print(i);break
for i in range(r, l-1, -1):
    if sum(map(int,str(i))) == x:print(i);break
