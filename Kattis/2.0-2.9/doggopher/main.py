l, *a = open(0)
X,Y,x,y = map(float, l.split())
for l in a:
    p,q = map(float, l.split())
    if ((X-p)**2+(Y-q)**2)*4<=(x-p)**2+(y-q)**2:
        print(f'The gopher can escape through the hole at ({p},{q}).')
        break
else:
    print('The gopher cannot escape.')
