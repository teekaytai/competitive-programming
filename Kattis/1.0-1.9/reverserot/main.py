O = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ_.'
*a,_ = open(0)
for l in a:
    n, s = l.split()
    print(''.join(O[(O.find(c)+int(n))%28] for c in s[::-1]))
