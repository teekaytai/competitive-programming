_, *a = open(0)
for l in a:
    i, frac = l.split()
    x, y = map(int, frac.split('/'))
    if y == 1: print(i, f'1/{x+1}')
    else:
        q, r = divmod(x, y)
        x, y = y, y-r
        print(i, f'{x}/{y+x*q}')
