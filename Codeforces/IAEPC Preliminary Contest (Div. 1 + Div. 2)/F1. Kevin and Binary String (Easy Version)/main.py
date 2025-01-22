import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or len(args) == 1 and args[0] or args

def main():
    *a, = map(int, input())
    *b, = map(int, input())
    if not a: print(0);return
    p = 0
    c = 0
    aa = []
    for x in a:
        if x != p:
            if c > 0:aa.append(c)
            p = x
            c = 1
        else:
            c += 1
    aa.append(c)
    p = 0
    c = 0
    bb = []
    for x in b:
        if x != p:
            if c > 0:bb.append(c)
            p = x
            c = 1
        else:
            c += 1
    bb.append(c)
    ao = a[0]
    bo = b[0]
    cs = [0, 0]
    i = 0
    for x in aa:
        cs[ao] += x
        ao = not ao
        if cs[bo] > bb[i]:print(-1); return
        if cs[bo] == bb[i]:
            i += 1; cs[bo] = 0; bo = 1 - bo
    while i < len(bb):
        if cs[bo] != bb[i]:print(-1); return
        if cs[bo] == bb[i]:
            i += 1; cs[bo] = 0; bo = 1 - bo
    else:
        v = (a[0]!=b[0]) + (a[-1] != b[-1])
        print((len(aa) - v - len(bb)) // 2 + v)

tcs = int(input())
for tc in range(tcs):
    main()
