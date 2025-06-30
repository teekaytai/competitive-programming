import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    s = input()
    t = set(input())
    print('Yes' if all(i == 0 or c.islower() or s[i-1] in t for i, c in enumerate(s)) else 'No')

main()
