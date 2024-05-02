for i, l in enumerate(open(0), start=1):
    _, *a = map(int, l.split())
    print(f'Case {i}:', min(a), max(a), max(a) - min(a))
