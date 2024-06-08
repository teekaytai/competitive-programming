import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    a, b = map(int, input().split())
    x = 1
    while a&x==b&x:x*=2
    print(x)

tcs = int(input())
for tc in range(tcs):
    main()
