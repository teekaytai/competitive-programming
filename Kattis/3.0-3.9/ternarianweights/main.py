_, *a = open(0)
for l in a:
    x = int(l)
    d = []
    while x:
        d.append(x%3)
        x //= 3
    d.append(0)
    for i, b in enumerate(d):
        if b > 1:
            d[i] -= 3
            d[i+1] += 1
    p = [3**i for i, b in enumerate(d) if b == -1]
    q = [3**i for i, b in enumerate(d) if b == 1]
    print('left pan:', *p[::-1])
    print('right pan:', *q[::-1])
