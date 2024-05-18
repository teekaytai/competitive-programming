import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def main():
    a, b, c = map(int, input().split())
    s = a + b + c
    print(min(s//2, a+b) if s%2==0 else -1)

tcs = int(input())
for tc in range(tcs):
    main()
