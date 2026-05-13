import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    s = input()
    a, b = 0, 1000000000
    for d in map(int, s):
        a2 = min(a, b) + d
        b2 = min(a + 1, b - 1) + 10 - d
        a, b = a2, b2
    print(min(a, b))

tcs = int(input())
for tc in range(tcs):
    main()
