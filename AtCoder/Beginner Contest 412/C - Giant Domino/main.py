import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    n = int(input())
    s, *a, t = map(int, input().split())
    a.sort()
    p = s
    c = 2
    i = 0
    while p * 2 < t:
        b = False
        while i < n - 2 and a[i] <= p * 2:
            i += 1
            b = True
        if not b:
            print(-1)
            break
        c += 1
        p = a[i - 1]
    else:
        print(c)

tcs = int(input())
for tc in range(tcs):
    main()
