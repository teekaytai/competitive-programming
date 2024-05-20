import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    x, y = map(int, input().split())
    a = (y+1) // 2
    x -= 4 * (y%2)
    x -= a * 7
    a += max((x+14) // 15, 0)
    print(a)

tcs = int(input())
for tc in range(tcs):
    main()
