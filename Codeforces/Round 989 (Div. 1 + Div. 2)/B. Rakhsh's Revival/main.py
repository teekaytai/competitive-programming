import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    n, m, k = map(int, input().split())
    c = 0
    t = 0
    x = 0
    for b in input():
        x = 0 if b == '1' or c else x + 1
        if c == 0 and x == m:
            t += 1
            c = k
            x = 0
        c = max(c-1, 0)
    print(t)

tcs = int(input())
for tc in range(tcs):
    main()
