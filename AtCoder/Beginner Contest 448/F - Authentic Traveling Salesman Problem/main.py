import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = [(i, tuple(map(int, input().split()))) for i in range(1, n + 1)]
    K = round(2e7 / n**.5)
    def f(t):
        p = t[1]
        i = p[0] // K
        return (i, p[1] if i % 2 == 0 else -p[1])
    a.sort(key=f)
    I = next(i for i, t in enumerate(a) if t[0] == 1)
    a = a[I:] + a[:I]
    print(' '.join(str(t[0]) for t in a))

main()
