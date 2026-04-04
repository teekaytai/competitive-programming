import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    m, d = [int(x) for x in input().split()]
    print('Yes' if (m, d) in [(1, 7), (3, 3), (5, 5), (7, 7), (9, 9)] else 'No')

main()
