import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    s = input()
    a = 0
    b = 0
    c = 0
    for x in s:
        if x == 'A':
            a += 1
        elif x == 'B':
            if a > 0:
                b += 1
                a -= 1
        else:
            if b > 0:
                c += 1
                b -= 1
    print(c)

main()
