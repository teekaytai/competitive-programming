import re
import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    a = []
    b = []
    lo = 0
    for _ in range(n):
        h1, m1, h2, m2 =map(int, re.split(r':| - ', input()))
        a.append(s:=h1*60+m1)
        b.append(e:=h2*60+m2)
    hi = 480
    while lo < hi:
        mid = (lo + hi+1) // 2
        p = a[0]
        for s, e in zip(a, b):
            if s < p:
                hi = mid - 1
                break
            l = e - s
            m = max(min(s - p, mid - l), 0)
            e2 = max(e + mid - m - l, e)
            p = e2
        else:
            if p != b[-1]:
                hi = mid - 1
            else:
                lo = mid
    p = a[0]
    for s, e in zip(a, b):
        l = e - s
        m = max(min(s - p, lo - l), 0)
        e2 = max(e + lo - m - l, e)
        p = e2
        h1, m1 = divmod(s - m, 60)
        h2, m2 = divmod(e2, 60)
        print(f'{h1}:{m1:02} - {h2}:{m2:02}')

main()
