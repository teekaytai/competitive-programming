*a,=open(0)
for l in a[2::2]:
    *b,=map(int, l.split())
    print(2*(max(b)-min(b)))
