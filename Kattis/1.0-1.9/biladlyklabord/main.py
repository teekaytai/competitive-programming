a=[]
for x in input():
    if not a or x!=a[-1]:a.append(x)
print(''.join(a))
