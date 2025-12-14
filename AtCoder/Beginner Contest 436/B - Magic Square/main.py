import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    g = [[0] * n for _ in range(n)]
    r = 0
    c = (n-1)//2
    g[r][c] = 1
    for i in range(n*n-1):
        if g[(r-1)%n][(c+1)%n]==0:
            r=(r-1)%n
            c=(c+1)%n
        else:
            r=(r+1)%n
        g[r][c] = i + 2
    for row in g:
        print(*row)

main()
