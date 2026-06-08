import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    a.sort(reverse=True)
    if all(a[i] == a[i - 2] % a[i - 1] for i in range(2, n)):
        print(*a[:2])
    else: print(-1)

tcs = int(input())
for tc in range(tcs):
    main()
