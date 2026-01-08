import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, k = [int(x) for x in input().split()]
    a = sorted(int(x) for x in input().split())
    a = sorted({*a})[:k - 1]
    for i in range(len(a)):
        if a[i] != i:
            print(i)
            return
    print(len(a))

tcs = int(input())
for tc in range(tcs):
    main()
