while W:=int(input()):
    mw = 0
    th = 0
    w = 0
    h = 0
    while True:
        x, y = map(int, input().split())
        if x==-1: break
        if w+x <= W:
            w += x
            h = max(h, y)
        else:
            w = x
            th += h
            h = y
        mw = max(mw, w)
    print(mw, 'x', th+h)
