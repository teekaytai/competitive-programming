x,y,z=1,0,0
for c in input():
    if c=='A':x,y=y,x
    elif c=='B':y,z=z,y
    else:x,z=z,x
print([x,y,z].index(1)+1)
