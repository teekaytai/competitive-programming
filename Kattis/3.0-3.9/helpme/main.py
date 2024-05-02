*I, = open(0)
g = [l[2::4] for l in I[1::2]]
w = []
b = []
for r, row in zip(range(1, 9), reversed(g)):
    for c, cell in zip('abcdefgh', row):
        if cell.isalpha():
            p = ('' if cell.upper()=='P' else cell.upper()) + c + str(r)
            if cell.isupper():
                w.append(p)
            else:
                b.append(p)
w.sort(key=lambda p: (-len(p), 'KQRBN'.find(p[0])))
b.sort(key=lambda p: (-len(p), 'KQRBN'.find(p[0]), -int(p[-1])))
print('White:', ','.join(w))
print('Black:', ','.join(b))
