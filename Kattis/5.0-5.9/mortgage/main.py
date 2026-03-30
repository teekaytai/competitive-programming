for l in open(0):
    x, y, n, r = map(float, l.split())
    if x == 0.0: break
    if r == 0.0:
        print('YES' if y * 12 * n >= x else 'NO')
        continue
    r = 1 / (1 + r / 1200)
    print('YES' if y * r * (r**(12 * n) - 1) / (r - 1) >= x else 'NO')
