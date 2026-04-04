import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = []
    b = []
    for _ in range(n):
        x, y = [int(x) for x in input().split()]
        a.append(x)
        b.append(y)
    m = int(input())
    have = [[0] * i for i in range(11)]
    s = []
    for _ in range(m):
        w = input()
        s.append(w)
        l = len(w)
        for i, c in enumerate(w):
            have[l][i] |= 1 << (ord(c) - 97)
    for w in s:
        if len(w) != n:
            print('No')
            continue
        print('Yes' if all(have[a[i]][b[i] - 1] & (1 << (ord(w[i]) - 97)) for i in range(n)) else 'No')

main()
