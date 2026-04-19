import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, m = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    s = set()
    b = 1
    for x in a:
        if x in s:
            b = 0
        s.add(x)
    print(['No', 'Yes'][b])
    print(['No', 'Yes'][len(s) == m])

main()
