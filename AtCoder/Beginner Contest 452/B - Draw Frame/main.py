import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, m = [int(x) for x in input().split()]
    for i in range(n):
        if i == 0 or i == n - 1:
            print('#' * m)
        else:
            print('#' + '.' * (m - 2) + '#')

main()
