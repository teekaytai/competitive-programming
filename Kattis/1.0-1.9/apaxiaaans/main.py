s=[]
for c in input():
    if not s or s[-1]!=c:s.append(c)
print(''.join(s))
