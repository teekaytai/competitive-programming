*a, = open(0)
print(sum(x==y for x,y in zip(a,a[1:])))
