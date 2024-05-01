*a,_ = open(0)
for l in a:
    x,y = map(int, l.split())
    print(*divmod(x,y), '/', y)
