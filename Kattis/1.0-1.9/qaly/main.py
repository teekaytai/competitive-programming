_,*a=map(float,open(0).read().split())
print(sum(x*y for x,y in zip(a[::2], a[1::2])))
