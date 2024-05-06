for i, l in enumerate(open(0), start=1):
    n, m = map(int, l.split())
    t = -m % 687
    n = (n + t) % 365
    while n:
        t += 687
        n = (n + 687) % 365
    print(f'Case {i}:', t)
