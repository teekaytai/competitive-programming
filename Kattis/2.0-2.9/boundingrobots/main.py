d = dict(zip('udlr', [(0, 1), (0, -1), (-1, 0), (1, 0)]))
while True:
    w, h = map(int, input().split())
    if not w: break
    X = x = Y = y = 0
    for _ in range(int(input())):
        a, b = input().split()
        b = int(b)
        dx, dy = d[a]
        X += b*dx
        x = min(max(x+b*dx, 0), w-1)
        Y += b*dy
        y = min(max(y+b*dy, 0), h-1)
    print('Robot thinks', X, Y)
    print('Actually at', x, y)
