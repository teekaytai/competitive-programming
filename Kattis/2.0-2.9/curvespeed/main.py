for l in open(0):
    r, s = map(float, l.split())
    print(round((r*(s+.16)/.067)**.5))
