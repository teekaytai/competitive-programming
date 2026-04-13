from fractions import Fraction

for _ in range(int(input())):
    n, *a = map(int, input().split())
    ps = list(zip(a[::2], a[1::2]))
    cx = Fraction(sum(a[::2]), n)
    cy = Fraction(sum(a[1::2]), n)
    I = list(range(n))
    def f(i):
        px, py = ps[i]
        dx = px - cx
        dy = py - cy
        r = (dx * dx + dy * dy) * (1 if dx > 0 or dx == 0 and dy <= 0 else -1)
        if dx == 0:
            return dy > 0, -float('inf'), r
        return dx < 0, dy / dx, r
    I.sort(key=f)
    print(*I)
