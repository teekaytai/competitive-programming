import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def q(a):
    print('?', len(a), *a, flush=True)
    return int(input())

def f(x):
    print('!', x, flush=True)

def main():
    n = 11343; k = 116
    x = q([k] * n)
    if x == 0:
        m = k ** 2
        x = q([1] * k**2)
        l = (m + x - 1) // x
        r = (m + x - 1 - 1) // (x - 1) - 1
        f(l)
    else:
        l = (n + x - 1) // x * k
        r = min((n + x - 1 - 1) // (x - 1) * k - 1, 100000)
        v = r - l
        if v == 0:
            f(l)
            return
        a = []
        for i in range(1, v + 1):
            a.append(l)
            a.append(i)
        y = v - (q(a) - v)
        f(l + y)

tcs = int(input())
for tc in range(tcs):
    main()
