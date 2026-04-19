import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def f(s):
    a = []
    for c in s:
        if c == '(':
            a.append(-1)
        elif c == 'x':
            if a and a[-1] > 0:
                a[-1] += 1
            else:
                a.append(1)
        else:
            if len(a) >= 2 and a[-1] == 2 and a[-2] == -1:
                a.pop()
                a.pop()
                if a and a[-1] > 0:
                    a[-1] += 2
                else:
                    a.append(2)
            else:
                a.append(-2)
    return a

def main():
    s = input()
    t = input()
    print(['No', 'Yes'][f(s) == f(t)])

tcs = int(input())
for tc in range(tcs):
    main()
