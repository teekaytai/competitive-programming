d = dict(zip('BFPVCGJKQSXZDTLMNR','111122222222334556'))
for l in open(0):
    a = []
    for c in l:
        x = d.get(c,'')
        if not a or a[-1] != x: a.append(x)
    print(''.join(a))
