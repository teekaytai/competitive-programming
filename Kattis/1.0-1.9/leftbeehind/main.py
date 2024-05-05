*a, _ = open(0)
for l in a:
    x, y = map(int, l.split())
    if x+y == 13: print('Never speak again.')
    else: print(['To the convention.','Undecided.','Left beehind.'][(y>x)+(y>=x)])
