import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    if input() == 'first':
        n = int(input())
        *a, = map(int, input().split())
        print(''.join(chr(96+x) for x in a))
    else:
        s = input()
        print(len(s))
        print(*(ord(c) - 96 for c in s))

main()
