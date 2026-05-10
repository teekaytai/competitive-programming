import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, k = [int(x) for x in input().split()]
    t = 0
    for i in range(n):
        a = [int(x) for x in input().split()]
        for j in range(1 - i % 2, n, 2):
            t ^= a[j] % (k + 1)
    print(['Alice', 'Bob'][t == 0])

tcs = int(input())
for tc in range(tcs):
    main()
