import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    s = input()
    t = input()
    i = 0
    j = 0
    x = 0
    while i < len(s) and j < len(t):
        if s[i] == t[j]:
            i += 1
            j += 1
        elif s[i] == 'A':
            i += 1
            x += 1
        elif t[j] == 'A':
            j += 1
            x += 1
        else:
            print(-1)
            return
    while i < len(s):
        if s[i] != 'A':
            print(-1)
            return
        i += 1
        x += 1
    while j < len(t):
        if t[j] != 'A':
            print(-1)
            return
        j += 1
        x += 1
    print(x)

main()
