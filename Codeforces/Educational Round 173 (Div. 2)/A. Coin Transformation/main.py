import sys

input = lambda: sys.stdin.readline().strip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs)

def f(x):
    return 1 if x <= 3 else 2 * f(x//4)

def main():
    n = int(input())
    print(f(n))

tcs = int(input())
for tc in range(tcs):
    main()
