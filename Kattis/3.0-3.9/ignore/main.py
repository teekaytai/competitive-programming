for x in map(int, open(0)):
    a = []
    while x:
        a.append('0125986'[x%7])
        x //= 7
    print(''.join(a))
