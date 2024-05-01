x, *a = open(0)
n, p, s = x.split()
for l in a:
    print(['REMOVE','KEEP'][p in l.split()[1:]])
