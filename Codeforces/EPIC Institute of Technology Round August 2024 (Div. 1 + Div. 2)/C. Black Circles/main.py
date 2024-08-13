import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def sd(x1, y1, x2, y2):
    return (x2 - x1) ** 2 + (y2 - y1) ** 2

def main():
    EPS = 1e-12
    n = int(input())
    X = []
    Y = []
    for _ in range(n):
        x, y = map(int, input().split())
        X.append(x)
        Y.append(y)
    xs, ys, xt, yt = map(int, input().split())
    dx1 = xt - xs
    dy1 = yt - ys
    d2 = sd(xs, ys, xt, yt)
    for x, y in zip(X, Y):
        dx2 = x - xs
        dy2 = y - ys
        t = (dx1 * dx2 + dy1 * dy2) / (dx1**2 + dy1**2)
        px = xs + t * dx1
        py = ys + t * dy1
        if -EPS <= t <= 1+EPS and sd(px, py, xs, ys) - sd(px, py, x, y) >= -EPS or d2 - sd(xt, yt, x, y) >= -EPS:
            print('NO')
            return
    print('YES')

tcs = int(input())
for tc in range(tcs):
    main()
