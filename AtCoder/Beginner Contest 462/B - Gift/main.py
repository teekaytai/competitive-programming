import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    g = [[] for _ in range(n + 1)]
    for i in range(1, n + 1):
        _, *a = [int(x) for x in input().split()]
        for x in a:
            g[x].append(i)
    for i in range(1, n + 1):
        print(len(g[i]), *g[i])

main()
