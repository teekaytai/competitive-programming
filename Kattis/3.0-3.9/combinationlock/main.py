*A, _ = open(0)
for l in A:
    a, b, c, d = [int(x)*9 for x in l.split()]
    print(1080+(a-b)%360+(c-b)%360+(c-d)%360)
