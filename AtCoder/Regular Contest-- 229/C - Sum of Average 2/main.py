import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    a = [int(x) for x in input().split()]
    a.sort()
    s = sum(a[i] - a[i] % 2 for i in range(n - 2)) + a[-1] // 2 + a[-2] // 2
    cs = [0, 0]
    for i in range(n - 2):
        cs[a[i] % 2] += 1
    b = a[-1] % 2
    for i in range(n - 2):
        if cs[1 - b]:
            b = 1 - b
            cs[b] -= 1
        else:
            cs[b] -= 1
            s += b
    s += b == 1 and a[-2] % 2
    print(s)

tcs = int(input())
for tc in range(tcs):
    main()
