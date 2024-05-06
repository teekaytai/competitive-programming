*a, = open(0).read().split()
print(sum(float(x)*(i+1) for i, x in enumerate(sorted(map(float, a[2::2]), reverse=True))))
