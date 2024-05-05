input()
s = []
for c in input():
    if c in '([{': s.append(c)
    elif not s or abs(ord(s[-1])-ord(c))>2: print('Invalid'); break
    else: s.pop()
else:
    print(['Invalid', 'Valid'][not s])
