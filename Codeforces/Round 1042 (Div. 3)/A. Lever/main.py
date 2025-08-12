import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    *a, = map(int, input().split())
    *b, = map(int, input().split())
    x = 0
    for p, q in zip(a, b):
        x += max(p - q, 0)
    print(x + 1)

tcs = int(input())
for tc in range(tcs):
    main()
