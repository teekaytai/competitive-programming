_,*a=open(0)
for l in a:
    if l.startswith('Simon says'):print(l[11:-1])
