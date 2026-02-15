import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    p, q = [int(x) for x in input().split()]
    print('Alice' if p*3<q*2 or p>=q else 'Bob')

tcs = int(input())
for tc in range(tcs):
    main()
