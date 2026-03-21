import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    g = []
    for _ in range(n):
        a = [int(x) for x in input().split()]
        g.append(a)
    can = False
    for c in range(n):
        for b in range(c):
            for a in range(b):
                can |= g[a][b - a - 1] + g[b][c - b - 1] < g[a][c - a - 1]
    print('Yes' if can else 'No')

main()
