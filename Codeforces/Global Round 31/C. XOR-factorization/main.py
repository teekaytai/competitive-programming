import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def MSB(x):
    return 1 << (x.bit_length() - 1) if x else 0

def main():
    n, k = map(int, input().split())
    if k % 2:
        a = [n] * k
    else:
        a = []
        t = n
        y = MSB(n)
        m = n - y
        for i in range(k - 1):
            b = MSB(m)
            m -= b
            x = y + max(b - 1, 0)
            a.append(x)
            y += b
            t ^= x
            assert x<=n
        a.append(t)
        assert t<=n
        # a = [n] * (k - 2)
        # x = MSB(n) + MSB(n - MSB(n)) - 1
        # a.append(x)
        # a.append(n ^ x)
    print(*a)
    # if k==4:
        # from itertools import*
        # printerr(bin(n)[2:], sum(a))
        # r = max(((i, j,j2, n^i^j^j2) for i in range(n+1) for j in range(n+1) for j2 in range(n+1)if n^i^j^j2<=n),key=sum)
        # for v in r:
        #     printerr(f'{v:0{n.bit_length()}b}')
        # printerr(r, sum(r))
        # assert sum(a)==sum(r)

tcs = int(input())
for tc in range(tcs):
    main()
