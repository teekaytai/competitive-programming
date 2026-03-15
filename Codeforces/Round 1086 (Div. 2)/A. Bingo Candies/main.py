import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    cs = [0] * (n*n+1)
    for _ in range(n):
        a = [int(x) for x in input().split()]
        for x in a:
            cs[x] += 1
    print('YES' if all(c <= n * (n - 1) for c in cs) else 'NO')

tcs = int(input())
for tc in range(tcs):
    main()
