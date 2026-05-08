import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    s = input()
    t = input()
    x = 0
    y = 0
    for c, d in zip(s, t):
        if c != ')': c, d = d, c
        x += 1 if c == '(' else -1
        y += 1 if d == '(' else -1
        if x < 0 or y < 0:
            print('NO')
            return
        if x < y: x, y = y, x
    print('YES' if x == y == 0 else 'NO')

tcs = int(input())
for tc in range(tcs):
    main()
