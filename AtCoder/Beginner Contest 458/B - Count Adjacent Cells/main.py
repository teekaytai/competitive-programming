import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, m = [int(x) for x in input().split()]
    if n == 1:
        print(*[1] + (m - 2) * [2] + [1] if m > 1 else [0])
        return
    if m == 1:
        print(1)
        for _ in range(n - 2):
            print(2)
        print(1)
        return
    print(*[2] + (m - 2) * [3] + [2])
    for _ in range(n - 2):
        print(*[3] + (m - 2) * [4] + [3])
    print(*[2] + (m - 2) * [3] + [2])

main()
