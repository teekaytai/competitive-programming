import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    can = False
    a = [int(x) for x in input().split()]
    a.append(0)
    c = 0
    for x in a:
        if x == 1:
            c += 1
        elif c != 0:
            can |= c != 2
            c = 0
    print('Alice' if can else 'Bob')

tcs = int(input())
for tc in range(tcs):
    main()
