import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

N = 400002
isp = [True] * N
mnp = [-1] * N
isp[:2] = [False, False]
for i in range(2, N):
    if not isp[i]: continue
    mnp[i] = i
    for j in range(i * 2, N, i):
        if isp[j]:
            isp[j] = False
            mnp[j] = i

def f(p, x):
    if x % 2 == 0:
        return True
    p2 = p * 2
    z = x
    while z > 1:
        q = mnp[z]
        m = p2 + (-p2 % (2*q))
        if m <= x:
            return True
        z //= q
    return False

def main():
    n = int(input())
    *a, = map(int, input().split())
    if n == 1:
        print(a[0])
        return
    a.sort()
    if any(isp[a[i]] for i in range(1, n)):
        print(-1)
    elif not isp[a[0]]:
        print(2)
    elif a[1] < a[0] * 2 or any(not f(a[0], a[i]) for i in range(1, n)):
        print(-1)
    else:
        print(a[0])


tcs = int(input())
for tc in range(tcs):
    main()
