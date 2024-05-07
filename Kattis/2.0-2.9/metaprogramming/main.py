d = {}
for l in open(0):
    o, *a = l.split()
    if o == 'define': d[a[1]] = int(a[0])
    elif a[0] not in d or a[2] not in d: print('undefined')
    else:
        print(str(eval(f'{d[a[0]]}{a[1] if a[1] != "=" else "=="}{d[a[2]]}')).lower())
