import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    xs = []
    ys = []
    for i in range(n):
        x,y = map(int, input().split())
        xs.append(x)
        ys.append(y)
    mnx = min(xs)
    mxx = max(xs)
    mny = min(ys)
    mxy = max(ys)
    lx = mxx- mnx
    ly = mxy - mny
    d = abs(lx - ly)
    if lx == ly and all(x in (mnx, mxx) or y in (mny, mxy) for x, y in zip(xs, ys)):
        print(mnx, mxx, mny, mxy)
    elif lx > ly and all(x in (mnx, mxx) or y in (mny - d, mxy) for x, y in zip(xs, ys)):
        print(mnx, mxx, mny- d, mxy)
    elif lx > ly and all(x in (mnx, mxx) or y in (mny, mxy + d) for x, y in zip(xs, ys)):
        print(mnx, mxx, mny, mxy + d)
    elif lx < ly and all(x in (mnx - d, mxx) or y in (mny, mxy) for x, y in zip(xs, ys)):
        print(mnx-d, mxx, mny, mxy)
    elif lx < ly and all(x in (mnx, mxx + d) or y in (mny, mxy) for x, y in zip(xs, ys)):
        print(mnx, mxx+d, mny, mxy)
    else:
        print('Impossible')

main()
