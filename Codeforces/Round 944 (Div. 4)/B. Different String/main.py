import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    s = input()
    if all(x == s[0] for x in s): print('NO')
    else:
        print('YES')
        t = ''.join(sorted(s))
        if t == s: t = t[::-1]
        print(t)

tcs = int(input())
for tc in range(tcs):
    main()
