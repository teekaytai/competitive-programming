import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def q(a, b):
    print('?', a, b, flush=True)
    return int(input())

def p(c):
    print('!', c, flush=True)

def main():
    n = int(input())
    bs = [False] * n
    *a, = map(int, input().split())
    for x in a: bs[x-1] = True
    I = next((i for i in range(n) if not bs[i]), -1)
    if I != -1:
        p('AB'[q(I + 1, 1 if I != 0 else 2) != 0])
    else:
        I = min(range(n), key=a.__getitem__)
        J = max(range(n), key=a.__getitem__)
        d = q(I+1, J+1)
        d2 = q(J+1, I+1)
        p('AB'[d==d2>=n-1])

tcs = int(input())
for tc in range(tcs):
    main()
