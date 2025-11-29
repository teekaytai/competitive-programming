import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    cs = [0] * (2 * n + 1)
    *a, = map(int, input().split())
    for x in a:
        cs[x] += 1
    o = 0
    eh = 0
    um = 0
    v = 0
    for c in cs:
        if c % 2 == 1:
            o += 1
            eh += c
        elif c:
            v += 1
            um += c - 2
    print(o + 2 * v - 2*(o == 0 and (n - v) % 2))

tcs = int(input())
for tc in range(tcs):
    main()
