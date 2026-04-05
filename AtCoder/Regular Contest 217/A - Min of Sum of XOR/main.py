import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def f(a, n, o=0):
    if n == 0:
        return
    if n == 1:
        a.append(o + 1)
        return
    if n == 2:
        a.append(o + 1)
        a.append(o + 2)
        return
    if n == 3:
        a.extend([o + 1, o + 3, o + 2])
        return
    b = 1 << (n.bit_length() - 1)
    f(a, b - 1, o)
    a.append(o + b)
    f(a, n - b, o + b)

def main():
    n = int(input())
    a = []
    f(a, n)
    print(' '.join(map(str, a)))

tcs = int(input())
for tc in range(tcs):
    main()
