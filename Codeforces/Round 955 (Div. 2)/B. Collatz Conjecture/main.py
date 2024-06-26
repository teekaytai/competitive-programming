import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    x, y, k = map(int, input().split())
    while k:
        if x < y:
            x = (x + k - 1) % (y-1) + 1
            break
        d = -x%y or y
        if d > k:
            x += k
            break
        k -= d
        x += d
        while x%y==0:
            x//=y
    print(x)

tcs = int(input())
for tc in range(tcs):
    main()
