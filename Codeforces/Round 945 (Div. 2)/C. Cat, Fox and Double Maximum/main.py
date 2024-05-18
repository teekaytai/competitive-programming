import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    *p, = map(int, input().split())
    if p.index(1) % 2 == 0:
        s = set(range(1, n-1, 2))
    else:
        s = set(range(2, n, 2))
    t = set(range(n)) - s
    I = sorted(s, key=p.__getitem__)
    J = sorted(t, key=p.__getitem__)
    q = [0] * n
    for i, v in zip(I, range(n, n-n//2+1, -1)): q[i] = v
    for i, v in zip(J, range(n-n//2+1, 0, -1)): q[i] = v
    print(*q)

tcs = int(input())
for tc in range(tcs):
    main()
