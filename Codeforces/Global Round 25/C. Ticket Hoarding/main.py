import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n, m, k = map(int, input().split())
    *a, = map(int, input().split())
    s = (k+m-1)//m
    I = sorted(range(n), key=a.__getitem__)
    b = I[:s]
    t = sum(a[i] for i in b) * m + sum(m*m*(s-i-1) for i in range(s))
    p = m * s - k
    print(t - p * (a[b[-1]] + m*(s-1)))


tcs = int(input())
for tc in range(tcs):
    main()
