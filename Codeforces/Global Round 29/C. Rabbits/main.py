import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = input()
    halp = False
    ready = False
    p = '1'
    for i, b in enumerate(a):
        if b == '0':
            if p == b:
                ready = True
                halp = False
            elif halp:
                ready = False
                halp = False
            elif ready or i == 0:
                ready = True
                halp = False
            else:
                halp = True
        else:
            if p == b:
                if halp:
                    print('NO')
                    return
                ready = False
        p = b
        # printerr(ready, halp)
    print('NO' if halp and a[-1] != '0' else 'YES')

tcs = int(input())
for tc in range(tcs):
    main()
