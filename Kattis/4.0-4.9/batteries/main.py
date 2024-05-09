*a, _ = map(int, open(0))
for x in a:
    t = 1
    i = 0
    while t < x:
        i += 1
        t += i
    print(i)
