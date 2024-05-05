_, *a = map(list, open(0))
for x in a:
    x.pop()
    d = 0
    for i in range(len(x)):
        if x[i] != '0': d = i
    x[d] = str(int(x[d])-1)
    print(int(''.join(x)))
