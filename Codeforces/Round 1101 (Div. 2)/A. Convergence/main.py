import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    a.sort()
    m = n // 2
    i = 0
    while i < m and a[i] != a[~i]:
        i += 1
    print(i)

tcs = int(input())
for tc in range(tcs):
    main()
