import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, m = [int(x) for x in input().split()]
    s = set(input())
    t = set(input())
    q = int(input())
    for _ in range(q):
        w = input()
        a = all(c in s for c in w)
        b = all(c in t for c in w)
        print(['Unknown', 'Takahashi', 'Aoki'][(not b) + 2 * (not a)])

main()
