import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    s = input()
    t = 0
    d1 = 0
    d2 = 0
    for c in s:
        if c == '4':
            t += 1
        elif c == '2':
            d2 = min(d2 + 1, d1)
        else:
            d1 = d1 + 1
    print(min(d1, d2) + t)

tcs = int(input())
for tc in range(tcs):
    main()
