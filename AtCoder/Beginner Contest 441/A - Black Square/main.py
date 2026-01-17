import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    p, q = [int(x) for x in input().split()]
    x, y = [int(x) for x in input().split()]
    print('Yes' if p<=x<=p+99 and q<=y<=q+99 else 'No')

main()
