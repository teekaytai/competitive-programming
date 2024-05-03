n, *a, = map(int, open(0))
i = n
while True:
    s = set()
    for x in a:
        y = x % i
        if y in s: break
        s.add(y)
    else:
        print(i)
        break
    i += 1
