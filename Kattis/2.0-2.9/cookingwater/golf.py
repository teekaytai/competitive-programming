_,*a=map(int,open(0).read().split())
print(['gunilla has a point','edward is right'][max(a[::2])>min(a[1::2])])