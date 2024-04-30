w, h = map(int, input().split())
n, m = map(int, input().split())
A = [tuple(map(int, input().split())) for _ in range(n)]
EPS = 1e-9
def f(R, c):
    x1 = R[0]; x2 = x1 + w
    y1 = R[1]; y2 = y1 + h
    xc, yc, r = c
    if x1 - EPS <= xc <= x2 + EPS and y1 - EPS <= yc <= y2 + EPS: return True
    if abs(xc - x1) <= r:
        dy = (r**2 - (xc - x1)**2) ** .5
        if yc - dy <= y2 + EPS and yc + dy >= y1 - EPS: return True
    if abs(xc - x2) <= r:
        dy = (r**2 - (xc - x2)**2) ** .5
        if yc - dy <= y2 + EPS and yc + dy >= y1 - EPS: return True
    if abs(yc - y1) <= r:
        dx = (r**2 - (yc - y1)**2) ** .5
        if xc - dx <= x2 + EPS and xc + dx >= x1 - EPS: return True
    if abs(yc - y2) <= r:
        dx = (r**2 - (yc - y2)**2) ** .5
        if xc - dx <= x2 + EPS and xc + dx >= x1 - EPS: return True
    return False

for _ in range(m):
    r = tuple(map(int, input().split()))
    print(f'DOOMSLUG {["GO", "STOP"][any(f(r, c) for c in A)]}!')
