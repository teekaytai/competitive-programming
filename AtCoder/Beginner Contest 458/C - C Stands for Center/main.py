import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    s = input()
    t = 0
    for i, x in enumerate(s):
        if x == 'C':
            t += min(i + 1, len(s) - i)
    print(t)

main()
