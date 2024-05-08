for s in map(str.strip,open(0)):
    a = []
    c = s[0]
    x = 0
    for d in s:
        if d == c: x += 1
        else: a.extend([str(x),c]); x = 1; c = d
    a.extend([str(x),c])
    print(''.join(a))
