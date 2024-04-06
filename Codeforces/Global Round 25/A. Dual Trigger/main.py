import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n = int(input())
    t = input()
    *a, = map(int, t)
    s = sum(a)
    print('YES' if s % 2 == 0 and (s != 2 or '11' not in t) else 'NO')
tcs = int(input())
for tc in range(tcs):
    main()
