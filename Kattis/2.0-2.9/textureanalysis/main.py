*a, _ = open(0)
for i, l in enumerate(a, start=1):
    p = 0
    d = -1
    for j in range(1, len(l)):
        if l[j] != '*': continue
        if d < 0: d = j - p
        elif j - p != d: print(i, 'NOT EVEN'); break
        p = j
    else:
        print(i, 'EVEN')
