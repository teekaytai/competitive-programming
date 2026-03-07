import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, x = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    for y in a:
        if y < x:
            x = y
            print(1)
        else:
            print(0)

main()
