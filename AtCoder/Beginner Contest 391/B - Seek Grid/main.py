import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, m = map(int, input().split())
    g1 = [input() for _ in range(n)]
    g2 = [input() for _ in range(m)]
    for i in range(n):
        for j in range(n - m + 1):
            if all(g1[i+k][j+l] == g2[k][l] for k in range(m) for l in range(m)):
                print(i + 1, j+1)
                return

main()
