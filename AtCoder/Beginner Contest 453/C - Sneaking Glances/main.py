import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def f(a, i, x):
    if i == len(a):
        return 0
    return max(f(a, i + 1, x - a[i]) + ((x - a[i]) * x < 0), f(a, i + 1, x + a[i]) + ((x + a[i]) * x < 0))

def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    print(f(a, 0, 0.5))

main()
