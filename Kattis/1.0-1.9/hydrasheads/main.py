*a, _ = open(0)
for l in a:
    h, t = map(int, l.split())
    if h%2 and t==0: print(-1); continue
    m = t//2 + t%2*2
    h += (t+1)//2
    print(m + h//2 + h%2*4)
