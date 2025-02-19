import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    t = 0
    a, b = 0, 0
    for x in map(int, input().split()):
        a += x == 1
        b = (b + (x == 2) * (a + b)) % 998244353
        t = (t + (x == 3) * b) % 998244353
    print(t)

tcs = int(input())
for tc in range(tcs):
    main()
