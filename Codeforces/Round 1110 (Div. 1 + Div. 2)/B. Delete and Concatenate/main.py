import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n, c = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    a.sort(reverse=True)
    t = 0
    m = (n + 1) // 2
    i = 0
    while i < n and (i < m or a[i] >= c):
        t += a[i] - c
        i += 1
    print(t)

tcs = int(input())
for tc in range(tcs):
    main()
