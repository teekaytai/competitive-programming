*a,_=map(int,open(0))
for x in a:
    p = 11
    while sum(map(int,str(x*p)))!=sum(map(int,str(x))):p+=1
    print(p)
