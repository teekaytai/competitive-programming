import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n, x, y = map(int, input().split())
    *a, = map(int, input().split())
    a.sort()
    a.append(a[0])
    s = 0
    u = a[0]
    c = []
    o = 0
    for v in a:
        d = (v - u) % n
        s += (d==2)
        u = v
        if d < 3: continue
        if d % 2 == 0:
            c.append(d)
        else:
            o += d // 2
    c.sort()
    for v in c:
        w = v // 2 - 2
        m = min(w, y)
        y -= m
        s += m
        x += m
        if y:
            y -= 1
            s += 2
            x += 1

    m = min(y, o)
    s += m
    x += m
    print(s + x - 2)

tcs = int(input())
for tc in range(tcs):
    main()
