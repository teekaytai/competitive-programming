*a, = open(0)
l = max(map(len, a))
print(sum((l-len(x))**2 for x in a[:-1]))
