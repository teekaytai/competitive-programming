s=[]
for x in input():
    if x == '<':s.pop()
    else:s.append(x)
print(''.join(s))
