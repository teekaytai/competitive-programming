l = []
h = []
while n:=int(input()):
    cmp = input()
    if cmp == 'right on':
        print(['Stan is dishonest', 'Stan may be honest'][all(x<n for x in l) and all(x>n for x in h)])
        l.clear()
        h.clear()
    elif cmp == 'too low': l.append(n)
    else: h.append(n)
