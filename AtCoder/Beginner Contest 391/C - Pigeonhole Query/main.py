import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, q = map(int, input().split())
    *a, = range(n)
    *c, = [1] * n
    v = 0
    for _ in range(q):
        o, *I = map(int, input().split())
        if o == 1:
            p, h = I
            p -= 1; h -= 1
            v -= c[a[p]] == 2
            c[a[p]] -= 1
            a[p] = h
            c[a[p]] += 1
            v += c[a[p]] == 2
        else:
            print(v)

main()
