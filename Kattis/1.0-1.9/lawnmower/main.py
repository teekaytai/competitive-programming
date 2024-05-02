while True:
    n, m, w = map(float, input().split())
    if not n: break
    *a, = map(float, input().split())
    *b, = map(float, input().split())
    can = True
    c = 0
    for x in sorted(a):
        if x > c + w/2: can = False; break
        c = x + w/2
    else:
        can &= c >= 75
    c = 0
    for x in sorted(b):
        if x > c + w/2: can = False; break
        c = x + w/2
    else:
        can &= c >= 100
    print(['NO', 'YES'][can])
