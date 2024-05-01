_,*a=open(0)
for l in a:print(1+sum(int(x)-1 for x in l.split()[1:]))
