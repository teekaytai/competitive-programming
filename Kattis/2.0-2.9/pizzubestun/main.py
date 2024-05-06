*a, = open(0).read().split()
print(sum(sorted(int(x) for x in a[2::2])[-1::-2]))
