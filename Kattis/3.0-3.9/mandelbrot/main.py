import sys
for i, line in enumerate(sys.stdin):
    x, y, r = line.split()
    x = float(x)
    y = float(y)
    c = complex(x, y)
    r = int(r)
    z = 0j
    diverges = False
    for _ in range(r):
        z = z * z + c
        if abs(z) > 2:
            diverges = True
            break
    print(f'Case {i + 1}:', 'OUT' if diverges else 'IN')
