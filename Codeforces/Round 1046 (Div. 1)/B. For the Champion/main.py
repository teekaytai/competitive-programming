import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def d(x1, y1, x2, y2):
    return abs(x2 - x1) + abs(y2 - y1)

def f(d, k):
    print('?', d, k, flush=True)
    return int(input())

def a(x, y):
    print('!', x, y, flush=True)

def main():
    n = int(input())
    e9 = 1000000000
    INF = 10000000000
    p = INF, 0, 0
    q = INF, 0, 0
    for _ in range(n):
        x, y = map(int, input().split())
        p = min(p, (d(x, y, e9, e9), x, y))
        q = min(q, (d(x, y, e9, -e9), x, y))
    f('U', e9)
    f('U', e9)
    f('R', e9)
    d1 = f('R', e9)
    f('D', e9)
    f('D', e9)
    f('D', e9)
    d2 = f('D', e9)
    m1 = -1
    c1 = p[2] + d1 - m1 * p[1] - 4 * e9
    m2 = 1
    c2 = q[2] - d2 - m2 * q[1] + 4 * e9
    X = (c2 - c1) // (m1 - m2)
    Y = m1 * X + c1
    a(X, Y)

tcs = int(input())
for tc in range(tcs):
    main()
