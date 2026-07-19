import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    for _ in range(n):
        a = [int(x) for x in input().split()]
        print(*[[3, 1, 4, 2][x - 1] for x in a])

main()
