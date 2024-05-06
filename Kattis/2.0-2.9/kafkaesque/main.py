_, *a, = map(int, open(0))
print(1+sum(x>y for x,y in zip(a,a[1:])))
