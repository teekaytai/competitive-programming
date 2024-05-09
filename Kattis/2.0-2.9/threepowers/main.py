*a, _ = map(int, open(0))
for x in a:
    b = f'{x-1:b}'
    r = []
    for i in range(len(b)):
        if b[-i-1] == '1': r.append(str(3**i))
    print('{', ', '.join(r), '}')
