import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def q(a):
    print('?', len(a), *a, flush=True)
    return int(input())

def main():
    x = q([1] * 100000)
    if x == 1:
        print('!', 100000, flush=True)
        return
    l = (100000 + x - 1) // x
    r = (100000 + x - 1 - 1) // (x - 1) - 1
    v = r - l
    if v == 0:
        print('!', l, flush=True)
        return
    a = []
    for i in range(1, v + 1):
        a.append(l)
        a.append(i)
    y = v - (q(a) - v)
    print('!', l + y, flush=True)

tcs = int(input())
for tc in range(tcs):
    main()
