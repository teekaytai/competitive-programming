import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def I(x):
    print('I', x, flush=True)
    return int(input())

def Q(x):
    print('Q', x, flush=True)
    return int(input())

def A(k, c):
    print('A', k, c, flush=True)

def f(n, x=1):
    t = 0
    b = 1 << (n - 1)
    for i in range(n):
        if Q(t + b) == x:
            t += b
        b >>= 1
    return t

def main():
    print(0, flush=True)
    n = int(input())
    T = (1 << n) - 1
    if I(T) == 1:
        A(3, T)
        return
    if Q(T) == 1:
        if I(0) == 2:
            A(1, T) if I(1) == 3 else A(2, T)
        else:
            A(2, f(n, 2))
    else:
        v = f(n)
        if I(0) == 2:
            A(1, v)
        else:
            A(3, T - v)

tcs = int(input())
for tc in range(tcs):
    main()
