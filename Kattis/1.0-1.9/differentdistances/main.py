*A,_ = open(0)
for l in A:
    a,b,c,d,p = map(float, l.split())
    print((abs(a-c)**p+abs(b-d)**p)**(1/p))
