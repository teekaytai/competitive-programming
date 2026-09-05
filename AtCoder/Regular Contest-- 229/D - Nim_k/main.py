import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    k = int(input())
    a = [int(x) for x in input().split()]
    a.sort()
    s = sum(a[i] - a[0] for i in range(1, k + 1))
    print('Alice' if a[0] % k != 0 or s >= k else 'Bob')

tcs = int(input())
for tc in range(tcs):
    main()
