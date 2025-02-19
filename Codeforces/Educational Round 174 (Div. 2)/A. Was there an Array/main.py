import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    input()
    print(['NO','YES']['1 0 1' not in input()])

tcs = int(input())
for tc in range(tcs):
    main()
