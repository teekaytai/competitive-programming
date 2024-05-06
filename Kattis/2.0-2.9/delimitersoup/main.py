input()
s = []
for i, c in enumerate(input()):
    if c == ' ': continue
    if c in '([{': s.append(c)
    elif not s or abs(ord(s[-1])-ord(c))>2: print(c, i); break
    else: s.pop()
else:
    print('ok so far')
