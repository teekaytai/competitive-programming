_, *a = map(int, open(0))
for x in a:
    p = 11**x
    t = 10**x
    i = 0
    while p >= t: p = p//11*2; i += 1
    print(*[2]*i, *[11]*(x-i))
