s = input()
a = input().split()
if len(s) != len(a): print(False)
else:
    d = {}
    c = set()
    for x, y in zip(s, a):
        if x in d:
            if d[x] != y: print(False); break
        else:
            if y in c: print(False); break
            d[x] = y
            c.add(y)
    else:
        print(True)
